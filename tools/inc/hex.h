#ifndef TOOLS_HEX_H_
#define TOOLS_HEX_H_

#include <string>

namespace tools {

class hex {
private:
	char ascii_table[16] = { 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
				0x38, 0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46 };
public:
	hex();
	virtual ~hex();
	hex(const hex&) = default;
	hex& operator=(const hex&) = default;
	hex(hex&&) noexcept = default;
	hex& operator=(hex&&) noexcept = default;

	int to_dec(char ch);
	void to_ascii(char *dest, unsigned char *src, int len);
	std::string to_string(const std::string &str);
};

} /* namespace tools */

#endif /* TOOLS_HEX_H_ */
