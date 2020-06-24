#ifndef MAC_BINARY_H_
#define MAC_BINARY_H_

#include "mac.h"

namespace ISO8583 {

class binary_mac: public mac {
public:
	binary_mac() = default;
	binary_mac(const std::string &mac_key);
	virtual ~binary_mac();
	binary_mac(const binary_mac&) = default;
	binary_mac& operator=(const binary_mac&) = default;
	binary_mac(binary_mac&&) noexcept = default;
	binary_mac& operator=(binary_mac&&) noexcept = default;


	std::optional<std::string> generate(std::string_view msg) override;
	bool verify(std::string_view msg, std::string_view msg_mac) override;
};

} /* namespace ISO8583 */

#endif /* MAC_BINARY_H_ */
