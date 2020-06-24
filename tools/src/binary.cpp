#include "binary.h"
#include <assert.h>

namespace tools {

binary::binary() {
}

binary::~binary() {
}

//convert nibble to hexadecimal character
char binary::nib_to_chr(unsigned char nib) {
	assert(nib <= 0x0F);

	if (nib < 10)
		return (char) ('0' + nib);
	return (char) ('A' + (nib - 10));
}

// Convert a binary buffer(bin) with length into a hexadecimal string hex.
int binary::to_hex(const unsigned char *bin, char *hex, int len) {
	assert(bin);
	assert(hex);
	assert(len > 0);

	unsigned char tmp;
	int ret = len * 2;
	while (len--) {
		tmp = *bin++;
		*hex++ = nib_to_chr((unsigned char) (tmp / 16));  //convert first nibble
		*hex++ = nib_to_chr((unsigned char) (tmp % 16)); //convert second nibble
	}
	*hex = 0;

	return ret;
}

} /* namespace tools */
