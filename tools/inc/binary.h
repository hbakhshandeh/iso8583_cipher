#ifndef TOOLS_BINARY_H_
#define TOOLS_BINARY_H_

namespace tools {

class binary {
public:
	binary();
	virtual ~binary();
	binary(const binary&) = default;
	binary& operator=(const binary&) = default;
	binary(binary&&) noexcept = default;
	binary& operator=(binary&&) noexcept = default;

	char nib_to_chr(unsigned char nib);
	int to_hex(const unsigned char *bin, char *hex, int len);
};

} /* namespace tools */

#endif /* TOOLS_BINARY_H_ */
