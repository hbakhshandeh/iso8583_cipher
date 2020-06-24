#include "cipher.h"
#include "pinblock_ascii.h"
#include "pinblock_binary.h"
#include "mac_ascii.h"
#include "mac_binary.h"

#include <assert.h>

namespace ISO8583 {

std::unique_ptr<pinblock> cipher::make_pinblock(message_type type) {

	assert((type == message_type::ascii || type == message_type::binary) &&
			"Message type is not correct.");

	if (type == message_type::ascii) {
		return std::unique_ptr<pinblock>(new ascii_pinblock);
	} else if (type == message_type::binary) {
		return std::unique_ptr<pinblock>(new binary_pinblock);
	}

	return nullptr;
}

std::unique_ptr<mac> cipher::make_mac(message_type type) {

	assert((type == message_type::ascii || type == message_type::binary)
					&& "Message type is not correct.");

	if (type == message_type::ascii) {
		return std::unique_ptr<mac>(new ascii_mac);
	} else if (type == message_type::binary) {
		return std::unique_ptr<mac>(new binary_mac);
	}

	return nullptr;
}



} /* namespace ISO8583 */
