#ifndef SRC_ISO_8583_H_
#define SRC_ISO_8583_H_

namespace ISO8583 {

enum LENGTH {
	key = 8, block_char = 8, block_string = 16, pan = 16, max_buffer = 512
};

} /* namespace ISO8583 */

#endif /* SRC_ISO_8583_H_ */
