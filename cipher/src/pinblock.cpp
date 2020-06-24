#include "pinblock.h"
#include <iomanip>
#include <iostream>

namespace ISO8583 {

pinblock::pinblock(const std::string &working_key, const std::string &translate_key) :
		wkey(working_key), tkey(translate_key) {
}
pinblock::~pinblock() {

}

std::string pinblock::get_user_key(std::string_view pan,
		std::string_view pin_block) {

	if (pan.size() != LENGTH::pan || pin_block.size() != LENGTH::block_string) {
		std::cout << "Data is wrong.\nPAN[" << pan << "]\nPINBLOCK["
				<< pin_block << "]\n";
		return nullptr;
	}

	char working_key[LENGTH::key + 1] = { 0x00 };
	ascii.to_hex(working_key, (char*) wkey.c_str(), wkey.length());

	char block_pin[LENGTH::block_char + 1] = { 0x00 };
	ascii.to_hex(block_pin, (char*) pin_block.data(), pin_block.length());

	unsigned char cipher[LENGTH::block_char + 1] = { 0x00 };
	cryp.des(cryp.mode::JUSTDES2_DECIPHER_, (unsigned char*) block_pin,
			(unsigned char*) working_key, cipher);

	std::string pan_block = std::string(4, '0').append(std::end(pan) - 13, std::end(pan) - 1);

	char ascii_ciphere[LENGTH::pan + 1] = { 0x00 };
	hex.to_ascii(ascii_ciphere, cipher, LENGTH::block_char);

	char key_block[LENGTH::pan + 1] = { 0x00 };
	x_or.ascii((unsigned char*) ascii_ciphere,
			(unsigned char*) pan_block.c_str(), (unsigned char*) key_block, LENGTH::pan);

	return std::string(key_block, 2, 4);
}

std::string pinblock::calculate(std::string_view pan,
		std::string_view user_key, std::string_view local_key) {

	if (pan.size() != LENGTH::pan || user_key.size() == 0
			|| local_key.size() != LENGTH::block_string) {
		std::cout << "Data is wrong.\nPAN[" << pan << "]\nUSER_KEY["
				<< user_key << "]\nLOCAL_KEY[" << local_key << "]" << std::endl;
		return nullptr;
	}

	std::string pan_block = std::string(4, '0').append(std::end(pan) - 13, std::end(pan) - 1);

	std::ostringstream key_block;
	key_block << std::setw(2) << std::setfill('0')
			<< std::to_string(user_key.size()) << user_key;
	key_block << std::string().append(LENGTH::pan - key_block.str().size(), 'F');

	char xor_pan_key[LENGTH::pan + 1] = { 0x00 };
	x_or.ascii((unsigned char*) pan_block.c_str(),
			(unsigned char*) key_block.str().c_str(),
			(unsigned char*) xor_pan_key, LENGTH::pan);

	char working_key[LENGTH::key + 1] = { 0x00 };
	ascii.to_hex(working_key, (char*) local_key.data(), local_key.size());

	char xor_block[LENGTH::block_char + 1] = { 0x00 };
	ascii.to_hex((char*) xor_block, xor_pan_key, LENGTH::pan);

	char cipher[LENGTH::block_char + 1] = { 0x00 };
	cryp.des(cryp.mode::JUSTDES2_ENCIPHER_, (unsigned char*) xor_block,
			(unsigned char*) working_key, (unsigned char*) cipher);

	char out[LENGTH::block_char * 2 + 1] = { 0x00 };
	hex.to_ascii(out, (unsigned char*) cipher, 8);

	return out;
}


} /* namespace ISO8583 */
