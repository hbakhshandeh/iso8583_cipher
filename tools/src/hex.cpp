#include "hex.h"
#include <assert.h>

namespace tools {

hex::hex() {
}

hex::~hex() {
}

int hex::to_dec(char ch) {
	int value = -1;

	if ((ch < '0') || (ch > '9')) {
		switch (ch) {
		case 'A':
			value = 10;
			break;
		case 'B':
			value = 11;
			break;
		case 'C':
			value = 12;
			break;
		case 'D':
			value = 13;
			break;
		case 'E':
			value = 14;
			break;
		case 'F':
			value = 15;
			break;
		}
	} else {
		value = ch - 48;
	}

	return value;
}

void hex::to_ascii(char *dest, unsigned char *src, int len) {
	assert(src);
	assert(len > 0);

	unsigned char lowByte = 0x0f;
	unsigned char highByte = 0x0f0;

	for (int j = 0; j < len; j++) {
		dest[j * 2] = ascii_table[(highByte & src[j]) >> 4];
		dest[j * 2 + 1] = ascii_table[(lowByte & src[j])];
	}

	return;
}

std::string hex::to_string(const std::string &str) {
	assert(str.size() > 0);

	char character[1024] = { 0x00 };

	int result;
	int index_out = 0;
	for (int index_in = 0; index_in < str.length(); index_in += 2) {
		result = to_dec(str[index_in]) * 16
				+ to_dec(str[index_in + 1]);

		sprintf(character + index_out, "%03d", result);
		index_out += 3;
	}

	return std::string(character, index_out);
}

} /* namespace tools */
