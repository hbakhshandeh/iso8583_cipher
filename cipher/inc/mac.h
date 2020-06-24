#ifndef MAC_H_
#define MAC_H_

#include "iso_8583.h"
#include "ascii.h"
#include "binary.h"
#include "crypto.h"
#include "exclusive_or.h"
#include <string>
#include <string_view>
#include <optional>

namespace ISO8583 {

class mac {
private:
	void encrypt_buffer(const char *bData, int len, unsigned char *mac,
			unsigned char *key);
protected:
//	tools::hex hex;
	tools::ascii ascii;
	tools::binary bin;
	tools::crypto cryp;
	tools::exclusive_or x_or;

	std::string mkey = { "1C1C1C1C1C1C1C1C" };

	void calculate(char* buff, int len, unsigned char* key,
			unsigned char* mac);
public:
	mac() = default;
	mac(const std::string &mac_key);
	virtual ~mac();
	mac(const mac&) = default;
	mac& operator=(const mac&) = default;
	mac(mac&&) noexcept = default;
	mac& operator=(mac&&) noexcept = default;

	virtual std::optional<std::string> generate(std::string_view msg) = 0;
	virtual bool verify(std::string_view msg, std::string_view msg_mac) = 0;
};

} /* namespace ISO8583 */

#endif /* MAC_H_ */
