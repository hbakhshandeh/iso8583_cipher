#ifndef PINBLOCK_ASCII_H_
#define PINBLOCK_ASCII_H_

#include "pinblock.h"

namespace ISO8583 {

class ascii_pinblock: public pinblock {
public:
	ascii_pinblock() = default;
	ascii_pinblock(const std::string &working_key, const std::string &translate_key);
	virtual ~ascii_pinblock();
	ascii_pinblock(const ascii_pinblock&) = default;
	ascii_pinblock& operator=(const ascii_pinblock&) = default;
	ascii_pinblock(ascii_pinblock&&) noexcept = default;
	ascii_pinblock& operator=(ascii_pinblock&&) noexcept = default;

	std::optional<std::string> translate(
			std::string_view pan, std::string_view pinb_lock) override;
	std::optional<std::string> generate(
			std::string_view pan, std::string_view user_key) override;
};

} /* namespace ISO8583 */

#endif /* PINBLOCK_ASCII_H_ */
