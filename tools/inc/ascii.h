#ifndef TOOLS_ASCII_H_
#define TOOLS_ASCII_H_

#include <string>

namespace tools {

class ascii {
public:
	ascii();
	virtual ~ascii();
	ascii(const ascii&) = default;
	ascii& operator=(const ascii&) = default;
	ascii(ascii&&) noexcept = default;
	ascii& operator=(ascii&&) noexcept = default;

	unsigned char to_hex(char ch);
	int to_bcd(char *dest, char *src, int len);
	void to_hex(char *dest, char *src, int len);
	std::string to_hex(const std::string &str);

};

} /* namespace tools */

#endif /* TOOLS_ASCII_H_ */
