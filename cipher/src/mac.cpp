#include "mac.h"
#include <assert.h>
#include <memory.h>

namespace ISO8583 {

mac::mac(const std::string &mac_key) :
		mkey(mac_key) {
}

mac::~mac() {
}

void mac::encrypt_buffer(const char *buff, int len, unsigned char *mac,
		unsigned char *key) {

	unsigned char tmp[LENGTH::block_char + 1] = { 0x00 };
	memcpy(tmp, buff, LENGTH::block_char);
	cryp.des(cryp.mode::JUSTDES2_ENCIPHER_, tmp, key, mac);

	unsigned char xor_block[LENGTH::block_char + 1] = { 0x00 };
	for (int idx = LENGTH::block_char; idx < len; idx += LENGTH::block_char) {
		memcpy(tmp, buff + idx, LENGTH::block_char);
		tmp[LENGTH::block_char] = 0;
		x_or.binary(mac, tmp, xor_block, LENGTH::block_char);
		cryp.des(cryp.mode::JUSTDES2_ENCIPHER_, xor_block, key, mac);
	}

	return;
}

void mac::calculate(char* buff, int len, unsigned char* key,
		unsigned char* mac) {
	assert(buff);
	assert(len > 0);
	assert(key);

	/*
	 * for mac calculation the lenght must be multiple of 8
	 * check and if not insert needed unsigned chars
	 */
	int size = len;
	int new_length = 0;
	if (((new_length = len + (8 - (len % 8))) != len) && (len % 8)) {
		unsigned char *tmp = (unsigned char *) malloc(new_length - len);
		memset(tmp, 0, new_length - len);

		memcpy(&buff[len], tmp, new_length - len);
		size += new_length - len;

		free(tmp);
	}

	unsigned char digit_mac[LENGTH::block_char + 1] = { 0x00 };
	encrypt_buffer(buff, size, digit_mac, key);

	unsigned char hex_mac[LENGTH::block_char * 2 + 1] = { 0x00 };
	bin.to_hex(digit_mac, (char*) hex_mac, LENGTH::block_char);

	memcpy(mac, hex_mac, LENGTH::block_char);		// first 4 digits mac data

	return;
}


} /* namespace ISO8583 */
