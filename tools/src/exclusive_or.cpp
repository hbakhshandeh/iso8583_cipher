#include "exclusive_or.h"
#include <assert.h>

namespace tools {

exclusive_or::exclusive_or() {
}

exclusive_or::~exclusive_or() {
}

char exclusive_or::decomp(char w) {

	if ((w >= 0) && (w <= 9)) {
		return (w + 0x30);
	}

	return (w + 0x37);
}

void exclusive_or::decomp(char x, char *r) {
	*(r + 1) = decomp(x & 0x0F);
	*r = decomp((x & 0xF0) >> 4);

	return;
}

void exclusive_or::decomp_all(unsigned char *a, unsigned char *b, unsigned short len) {

	for (int i = 0; i < len; i++) {
		decomp(a[i], (char*)(b + (2 * i)));
	}

	return;
}

unsigned char exclusive_or::comp(unsigned char w) {

	if ((w >= '0') && (w <= '9')) {
		return (w - 0x30);
	}

	return (w - 0x37);
}

void exclusive_or::comp(const unsigned char *x, unsigned char *r) {

	*r = comp(x[1]) + (16 * comp(x[0]));

	return;
}

void exclusive_or::comp_all(const unsigned char *a, unsigned char *b,
		unsigned short len) {

	for (int i = 0; i < len; i++) {
		comp(a + (2 * i), (b + i));
	}

	return;
}

void exclusive_or::ascii(const unsigned char *src1, const unsigned char *src2,
		unsigned char *dest, unsigned short len) {
	assert(src1);
	assert(src2);
	assert(dest);
	assert(len > 0);

	const int block_length = len / 2;

	unsigned char entree1[block_length + 1] = { 0x00 };
	comp_all(src1, entree1, block_length);

	unsigned char entree2[block_length + 1] = { 0x00 };
	comp_all(src2, entree2, block_length);

	unsigned char strSortie[block_length + 1] = { 0x00 };
	for (int i = 0; i < block_length; i++) {
		*(strSortie + i) = *(entree1 + i) ^ *(entree2 + i);
	}

	decomp_all(strSortie, dest, block_length);

	return;
}

void exclusive_or::binary(const unsigned char *src1,
		const unsigned char *src2, unsigned char *dest,
		unsigned short len) {
	assert(src1);
	assert(src2);
	assert(dest);
	assert(len > 0);

	while (len--) {
		*dest++ = *src1++ ^ *src2++;
	}
}

} /* namespace tools */
