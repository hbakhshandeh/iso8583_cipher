#include "crypto.h"
#include <assert.h>

namespace tools {

crypto::crypto() {
}

crypto::~crypto() {
}

// TODO: Legacy code. It must be replaced or cleaned.
void crypto::des(mode selector, unsigned char *input, unsigned char *key,
		unsigned char *output) {
	assert(input);
	assert(key);

	unsigned long s[64];

	s[0] = 0xD8D8DBBC;
	s[1] = 0xD737D1C1;
	s[2] = 0x8B047441;
	s[3] = 0x35A9E2FE;
	s[4] = 0x146E9560;
	s[5] = 0x8A420CFB;
	s[6] = 0xF8FBAF1F;
	s[7] = 0xC7B4DD10;
	s[8] = 0x7A97A497;
	s[9] = 0x4CFCFA1C;
	s[10] = 0x456ADA86;
	s[11] = 0xFAC710E9;
	s[12] = 0xE52149EF;
	s[13] = 0x338D2004;
	s[14] = 0x1E5580F1;
	s[15] = 0xE04A2F3D;
	s[16] = 0x870A4E20;
	s[17] = 0x28BE9C1F;
	s[18] = 0x74D5E339;
	s[19] = 0x8240BD00;
	s[20] = 0x6AA1ABC3;
	s[21] = 0x3F55E2A8;
	s[22] = 0xAF1F56BC;
	s[23] = 0x51BB11CF;
	s[24] = 0xB7FC035E;
	s[25] = 0xE00307B0;
	s[26] = 0x08A3B44B;
	s[27] = 0x3F786D67;
	s[28] = 0x09967CBC;
	s[29] = 0x45EB7B47;
	s[30] = 0xF3683962;
	s[31] = 0x9C14C6D2;
	s[32] = 0x16452B42;
	s[33] = 0xADDACEBA;
	s[34] = 0x58F91ABC;
	s[35] = 0x8B68B547;
	s[36] = 0xFAA36659;
	s[37] = 0x47BF8901;
	s[38] = 0x671AEBA9;
	s[39] = 0x30C452AB;
	s[40] = 0x493893E1;
	s[41] = 0x72C16866;
	s[42] = 0xB7C78574;
	s[43] = 0xCD1E6B9A;
	s[44] = 0xB6DCD49C;
	s[45] = 0x9822B7FB;
	s[46] = 0x89B07E43;
	s[47] = 0x77B78644;
	s[48] = 0xA566F5DF;
	s[49] = 0xD22D6AC3;
	s[50] = 0xAF9A0423;
	s[51] = 0x77B71BBC;
	s[52] = 0x81DC043E;
	s[53] = 0xC8837314;
	s[54] = 0x78659153;
	s[55] = 0xAF782C7D;
	s[56] = 0x8C0F78A0;
	s[57] = 0x0D3095EF;
	s[58] = 0x7A506B8E;
	s[59] = 0x8445D610;
	s[60] = 0x5223AB47;
	s[61] = 0x724C0C34;
	s[62] = 0x45AF54BC;
	s[63] = 0x38DBF9CB;

	unsigned long x, c, d, r, l;
	l = r = c = d = 0;

	int i = 7;
	do {
		x = input[i];
		l = l << 1 | (x & 1 << 0) | (x & 1 << 2) << 6 | (x & 1 << 4) << 12
				| (x & 1 << 6) << 18;
		r = r << 1 | (x & 1 << 1) >> 1 | (x & 1 << 3) << 5 | (x & 1 << 5) << 11
				| (x & 1 << 7) << 17;
		x = key[i];
		c = c << 1 | (x & 1 << 7) << 17 | (x & 1 << 6) << 10 | (x & 1 << 5) << 3
				| (x & 1 << 4) >> 4;
		d = d << 1 | (x & 1 << 1) << 19 | (x & 1 << 2) << 10
				| (x & 1 << 3) << 1;
	} while (--i >= 0);

	d |= c & 0x0F;
	c >>= 4;
	i = 24;
	if (selector != mode::JUSTDES2_ENCIPHER_) {
		goto startRound;
	}

leftBy1:
	c = c << 1 | c >> 27 & 1;
	d = d << 1 | d >> 27 & 1;

startRound:
	x = s[(r >> 26 & 62 | r & 1)
			^ (c >> 6 & 32 | c >> 13 & 16 | c >> 1 & 8 | c >> 25 & 4
					| c >> 22 & 2 | c >> 14 & 1)] & 0x00808202 ^ l;
	x ^= s[(r >> 23 & 63)
			^ (c >> 20 & 32 | c << 4 & 16 | c >> 10 & 8 | c >> 20 & 4
					| c >> 6 & 2 | c >> 18 & 1)] & 0x40084010;
	x ^= s[(r >> 19 & 63)
			^ (c & 32 | c >> 5 & 16 | c >> 13 & 8 | c >> 22 & 4 | c >> 1 & 2
					| c >> 20 & 1)] & 0x04010104;
	x ^= s[(r >> 15 & 63)
			^ (c >> 7 & 32 | c >> 17 & 16 | c << 2 & 8 | c >> 6 & 4
					| c >> 14 & 2 | c >> 26 & 1)] & 0x80401040;
	x ^= s[(r >> 11 & 63)
			^ (d >> 10 & 32 | d & 16 | d >> 22 & 8 | d >> 17 & 4 | d >> 8 & 2
					| d >> 1 & 1)] & 0x21040080;
	x ^= s[(r >> 7 & 63)
			^ (d >> 21 & 32 | d >> 12 & 16 | d >> 2 & 8 | d >> 9 & 4
					| d >> 22 & 2 | d >> 8 & 1)] & 0x10202008;
	x ^= s[(r >> 3 & 63)
			^ (d >> 7 & 32 | d >> 3 & 16 | d >> 14 & 8 | d << 2 & 4
					| d >> 21 & 2 | d >> 3 & 1)] & 0x02100401;
	x ^= s[(r & 31 | r >> 26 & 32)
			^ (d >> 19 & 32 | d >> 6 & 16 | d >> 11 & 8 | d >> 4 & 4
					| d >> 19 & 2 | d >> 27 & 1)] & 0x08020820;
	l = r;
	r = x;

	if ((i & 7) == 0) {
		i -= 2;
		if (selector == mode::JUSTDES2_ENCIPHER_)
			goto leftBy1;
		c = c >> 1 | (c & 1) << 27;
		d = d >> 1 | (d & 1) << 27;
		goto startRound;
	}

	if (i != 6) {
		--i;
		if (selector == mode::JUSTDES2_ENCIPHER_) {
			c = c << 2 | c >> 26 & 3;
			d = d << 2 | d >> 26 & 3;
			goto startRound;
		} else {
			c = c >> 2 | (c & 3) << 26;
			d = d >> 2 | (d & 3) << 26;
			goto startRound;
		}
	}

	i = 7;
	do {
		*output++ = (char) (r & 1 << 0 | r >> 6 & 1 << 2 | r >> 12 & 1 << 4
				| r >> 18 & 1 << 6 | l << 1 & 1 << 1 | l >> 5 & 1 << 3
				| l >> 11 & 1 << 5 | l >> 17 & 1 << 7);
		l >>= 1;
		r >>= 1;
	} while (--i >= 0);

	return;
}

// Input and output: 8 bytes, key: 24 bytes (3 Components)
void crypto::triple_des(mode selector, unsigned char *input,
		unsigned char *key, unsigned char *output) {
	assert(input);
	assert(key);

	unsigned char out_key_enc[8] = { 0x00 };
	unsigned char out_key_dec[8] = { 0x00 };

	if (selector == mode::JUSTDES2_ENCIPHER_) {
		des(mode::JUSTDES2_ENCIPHER_, input, key, out_key_enc);
		des(mode::JUSTDES2_DECIPHER_, out_key_enc, key + 8, out_key_dec);
		des(mode::JUSTDES2_ENCIPHER_, out_key_dec, key + 16, output);
	} else {
		des(mode::JUSTDES2_DECIPHER_, input, key + 16, out_key_enc);
		des(mode::JUSTDES2_ENCIPHER_, out_key_enc, key + 8, out_key_dec);
		des(mode::JUSTDES2_DECIPHER_, out_key_dec, key, output);
	}
	return;
}

} /* namespace tools */
