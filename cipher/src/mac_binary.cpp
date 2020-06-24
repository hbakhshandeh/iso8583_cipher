#include "mac_binary.h"
#include <iostream>

namespace ISO8583 {

binary_mac::binary_mac(const std::string &mac_key) :
		mac(mac_key) {
}

binary_mac::~binary_mac() {
}

std::optional<std::string> binary_mac::generate(std::string_view msg) {
	if (msg.empty()) {
		std::cout << "Message is empty." << std::endl;
		return std::nullopt;
	}

	char mac_key[LENGTH::key + 1] = { 0x00 };
	ascii.to_hex(mac_key, (char*) mkey.c_str(), mkey.length());

	char mac[LENGTH::block_char + 1] = { 0x00 };
	calculate((char*) msg.data(), msg.length(), (unsigned char*) mac_key,
			(unsigned char*) mac);

	return mac;
}

bool binary_mac::verify(std::string_view msg, std::string_view msg_mac) {
	if (msg.empty() || msg_mac.empty()) {
		std::cout << "Input data is wrong.\nMessage[" << msg << "]\nMAC["
				<< msg_mac << "]\n";
		return false;
	}

	char mac_key[LENGTH::key + 1] = { 0x00 };
	ascii.to_hex(mac_key, (char*) mkey.c_str(), mkey.length());

	char mac[LENGTH::block_char + 1] = { 0x00 };
	calculate((char*) msg.data(), msg.length(), (unsigned char*) mac_key,
			(unsigned char*) mac);

	if (msg_mac.compare(mac)) {
		return false;
	}

	return true;
}

} /* namespace ISO8583 */
