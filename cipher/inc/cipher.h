#ifndef CIPHER_H_
#define CIPHER_H_

#include "mac.h"
#include "pinblock.h"

#include <memory>

namespace ISO8583 {

enum class message_type {
	binary, ascii
};

class cipher {
public:
	cipher() = delete;
	virtual ~cipher();
	cipher(const cipher&) = delete;
	cipher& operator=(const cipher&) = delete;
	cipher(cipher&&) noexcept = delete;
	cipher& operator=(cipher&) noexcept = delete;

	static std::unique_ptr<pinblock> make_pinblock(message_type type);
	static std::unique_ptr<mac> make_mac(message_type type);
};

} /* namespace ISO8583 */

#endif /* CIPHER_H_ */
