#ifndef PINBLOCK_BINARY_H_
#define PINBLOCK_BINARY_H_

#include "pinblock.h"

namespace ISO8583 {

class binary_pinblock: public pinblock {
public:
	binary_pinblock() = default;
	explicit binary_pinblock(const std::string &working_key, const std::string &translate_key);
	virtual ~binary_pinblock();
	binary_pinblock(const binary_pinblock&) = default;
	binary_pinblock& operator=(const binary_pinblock&) = default;
	binary_pinblock(binary_pinblock&&) noexcept = default;
	binary_pinblock& operator=(binary_pinblock&&) noexcept = default;

	std::optional<std::string> translate(
			std::string_view pan, std::string_view pin_block) override;
	std::optional<std::string> generate(
			std::string_view pan, std::string_view user_key) override;

};

} /* namespace ISO8583 */

#endif /* PINBLOCK_BINARY_H_ */
