#ifndef MAC_ASCII_H_
#define MAC_ASCII_H_

#include "mac.h"

namespace ISO8583 {

class ascii_mac: public mac {
public:
	ascii_mac() = default;
	ascii_mac(const std::string &mac_key);
	virtual ~ascii_mac();
	ascii_mac(const ascii_mac&) = default;
	ascii_mac& operator=(const ascii_mac&) = default;
	ascii_mac(ascii_mac&&) noexcept = default;
	ascii_mac& operator=(ascii_mac&&) noexcept = default;

	std::optional<std::string> generate(std::string_view msg) override;
	bool verify(std::string_view msg, std::string_view msg_mac) override;
};

} /* namespace ISO8583 */

#endif /* MAC_ASCII_H_ */
