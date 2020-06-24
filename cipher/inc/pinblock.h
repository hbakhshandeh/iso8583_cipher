#ifndef PINBLOCK_H_
#define PINBLOCK_H_

#include "iso_8583.h"
#include "hex.h"
#include "ascii.h"
#include "crypto.h"
#include "exclusive_or.h"

#include <string_view>
#include <variant>
#include <optional>

namespace ISO8583 {

class pinblock {
protected:
	tools::hex hex;
	tools::ascii ascii;
	tools::crypto cryp;
	tools::exclusive_or x_or;

	std::string wkey = { "1C1C1C1C1C1C1C1C" };
	std::string tkey = { "1A1A1A1A1A1A1A1A" };

	std::string calculate(std::string_view pan, std::string_view user_key,
			std::string_view local_key);
	std::string get_user_key(std::string_view pan, std::string_view pin_block);

public:
	pinblock() = default;
	explicit pinblock(const std::string &working_key,
			const std::string &translate_key);
	virtual ~pinblock();
	pinblock(const pinblock&) = default;
	pinblock& operator=(const pinblock&) = default;
	pinblock(pinblock&&) noexcept = default;
	pinblock& operator=(pinblock&&) noexcept = default;

	virtual std::optional<std::string> translate(
			std::string_view pan, std::string_view pin_block) = 0;
	virtual std::optional<std::string> generate(
			std::string_view pan, std::string_view user_key) = 0;

};

} /* namespace ISO8583 */

#endif /* PINBLOCK_H_ */
