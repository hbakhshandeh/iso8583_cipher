#ifndef TOOLS_EXCLUSIVE_OR_H_
#define TOOLS_EXCLUSIVE_OR_H_

namespace tools {

class exclusive_or {
private:
	char decomp(char w);
	void decomp(char x, char *r);
	void decomp_all(unsigned char *a, unsigned char *b, unsigned short len);

	unsigned char comp(unsigned char w);
	void comp(const unsigned char *x, unsigned char *r);
	void comp_all(const unsigned char *a, unsigned char *b,
			unsigned short length);

public:
	exclusive_or();
	virtual ~exclusive_or();
	exclusive_or(const exclusive_or&) = default;
	exclusive_or& operator=(const exclusive_or&) = default;
	exclusive_or(exclusive_or&&) noexcept = default;
	exclusive_or& operator=(exclusive_or&&) noexcept = default;

	void ascii(const unsigned char *src1, const unsigned char *src2,
			unsigned char *dest, unsigned short len);
	void binary(const unsigned char *src1, const unsigned char *src2,
			unsigned char *dest, unsigned short len);
};

} /* namespace tools */

#endif /* TOOLS_EXCLUSIVE_OR_H_ */
