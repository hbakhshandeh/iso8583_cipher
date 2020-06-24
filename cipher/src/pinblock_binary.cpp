
#include "pinblock_binary.h"
#include <iostream>

namespace ISO8583 {

binary_pinblock::binary_pinblock(const std::string &working_key,
		const std::string &translate_key) :
		pinblock(working_key, translate_key) {
}

binary_pinblock::~binary_pinblock() {

}

std::optional<std::string> binary_pinblock::translate(std::string_view pan,
		std::string_view pin_block) {

	if (pan.size() != LENGTH::pan || pin_block.size() != LENGTH::block_string) {
			std::cout << "Data is wrong.\nPAN[" << pan << "]\nPINBLOCK[" << pin_block << "]\n";
		return std::nullopt;
	}

	std::string user_key = get_user_key(pan, pin_block);
	if (user_key.size() == 0) {
		return nullptr;
	}

	// translation key
	std::string translated_pb = calculate(pan, user_key, tkey);
	if (translated_pb.size() == 0) {
		return nullptr;
	}

	char block[LENGTH::block_char + 1] = { 0x00 };
	ascii.to_hex(block, (char*)translated_pb.c_str(), translated_pb.length());

	return block;
}

std::optional<std::string> binary_pinblock::generate(std::string_view pan,
		std::string_view user_key) {

	if (pan.size() != LENGTH::pan || user_key.size() == 0) {
		std::cout << "Data is wrong.\nPAN[" << pan << "]\nUSER_KEY" << user_key << "]\n";
		return std::nullopt;
	}

	// working key
	std::string generated_pb = calculate(pan, user_key, wkey);
	if (generated_pb.size() == 0) {
		return nullptr;
	}

	char block[LENGTH::block_char + 1] = { 0x00 };
	ascii.to_hex(block, (char*)generated_pb.c_str(), generated_pb.length());

	return block;
}

} /* namespace ISO8583 */
