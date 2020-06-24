#include "pinblock_ascii.h"

#include <iostream>

namespace ISO8583 {

ascii_pinblock::ascii_pinblock(const std::string &working_key,
		const std::string &translate_key) :
		pinblock(working_key, translate_key) {

}
ascii_pinblock::~ascii_pinblock() {

}

std::optional<std::string> ascii_pinblock::translate(
		std::string_view pan, std::string_view pin_block) {

	if (pan.size() != LENGTH::pan || pin_block.size() != LENGTH::block_string) {
		std::cout << "Data is wrong.\nPAN[" << pan << "]\nPINBLOCK[" << pin_block << "]\n";
		return std::nullopt;
	}

	std::string user_key = get_user_key(pan, pin_block);
	if (user_key.size() == 0) {
		return nullptr;
	}

	// translation key
	return calculate(pan, user_key, tkey);
}

std::optional<std::string> ascii_pinblock::generate(
		std::string_view pan, std::string_view user_key) {

	if (pan.size() != LENGTH::pan || user_key.size() == 0) {
		std::cout << "Data is wrong.\nPAN[" << pan << "]\nUSER_KEY[" << user_key << "]\n";
		return std::nullopt;
	}

	// working key
	return calculate(pan, user_key, wkey);
}

} /* namespace ISO8583 */
