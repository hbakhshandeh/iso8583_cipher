#include "ascii.h"
#include <assert.h>

namespace tools {

ascii::ascii() {
}

ascii::~ascii() {
}

unsigned char ascii::to_hex(char ch) {

	if ((ch >= '0') && (ch <= '9')) {
		return (ch - '0');
	}

	if ((ch >= 'A') && (ch <= 'F')) {
		return (ch - 'A' + 10);
	}

	if ((ch >= 'a') && (ch <= 'f')) {
		return (ch - 'a' + 10);
	}

	return 0x00;
}

int ascii::to_bcd(char *dest, char *src, int len) {
	assert(src);
	assert(len);

	unsigned char c1;
	unsigned char c2;
	int j;
	for (int i = 0; i < len; i++) {
		j = i * 2;
		c1 = src[j] << 4;
		c2 = src[j + 1] & 0x0F;
		*(dest + i) = c1 | c2;
	}

	return 0;
}

void ascii::to_hex(char *dest, char *src, int len) {
	assert(src);
	assert(len);

	char octet;
	for (int j = 0; j < len / 2; j++) {
		octet = to_hex(src[2 * j]);
		dest[j] = octet << 4;
		octet = to_hex(src[2 * j + 1]);
		dest[j] |= octet;
	}

	return;
}

std::string ascii::to_hex(const std::string &str) {

	char out_arr[512] = { 0x00 };

	char ch;
	for (unsigned int i = 0; i < str.length(); i++) {
		ch = str[i];
		switch (ch) {
		case ':':
			out_arr[i] = 'A';
			break;
		case ';':
			out_arr[i] = 'B';
			break;
		case '<':
			out_arr[i] = 'C';
			break;
		case '=':
			out_arr[i] = 'D';
			break;
		case '>':
			out_arr[i] = 'E';
			break;
		case '?':
			out_arr[i] = 'F';
			break;
		default:
			out_arr[i] = str[i];
		}
	}
	return std::string(out_arr);
}

} /* namespace tools */
