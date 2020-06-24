#ifndef TOOLS_CRYPTO_H_
#define TOOLS_CRYPTO_H_

namespace tools {

class crypto {
public:
	crypto();
	virtual ~crypto();
	crypto(const crypto&) = default;
	crypto& operator=(const crypto&) = default;
	crypto(crypto&&) noexcept = default;
	crypto& operator=(crypto&&) noexcept= default;

	enum class mode {
		JUSTDES2_ENCIPHER_ = 0,
		JUSTDES2_DECIPHER_ = 1
	};

	void des(mode selector, unsigned char *input, unsigned char *key,
			unsigned char *output);
	void triple_des(mode selector, unsigned char *input, unsigned char *key,
			unsigned char *output);
};

} /* namespace tools */

#endif /* TOOLS_CRYPTO_H_ */
