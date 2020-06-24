#include "gtest/gtest.h"
#include "cipher.h"

#include <memory>

class test_pinblock: public ::testing::Test {
protected:
	std::unique_ptr<ISO8583::pinblock> ascii_pin = { nullptr };
	std::unique_ptr<ISO8583::pinblock> binary_pin = { nullptr };
public:
	void SetUp() {
		ascii_pin = ISO8583::cipher::make_pinblock(ISO8583::message_type::ascii);
		binary_pin = ISO8583::cipher::make_pinblock(ISO8583::message_type::binary);
	}

	void TearDown() {
	}
};

// unit test ascii message
TEST_F(test_pinblock, ascii_generation) {

	std::string pan = "1237890123456749";
	std::string user_key = "1234";
	std::string expected_pinblock = "564EE4E837678F34";

	auto generated_pinblock = ascii_pin->generate(pan, user_key).value();
	EXPECT_STREQ(generated_pinblock.c_str(), expected_pinblock.c_str());

}

TEST_F(test_pinblock, ascii_translation) {

	std::string pan = "1237890123456749";
	std::string pinblock = "564EE4E837678F34";
	std::string expected_pinblock = "AADAF5DE704009F5";

	auto translated_pinblock = ascii_pin->translate(pan, pinblock).value();
	EXPECT_STREQ(translated_pinblock.c_str(), expected_pinblock.c_str());
}

// unit test binary message
TEST_F(test_pinblock, binary_generation) {

	std::string pan = "1237890123456749";
	std::string user_key = "1234";
	std::string expected_pinblock = "\x56\x4E\xE4\xE8\x37\x67\x8F\x34";

	auto generated_pinblock = binary_pin->generate(pan, user_key).value();
	EXPECT_STREQ(generated_pinblock.c_str(), expected_pinblock.c_str());
}

TEST_F(test_pinblock, binary_translation) {

	std::string pan = "1237890123456749";
	std::string pinblock = "564EE4E837678F34";
	std::string expected_pinblock = "\xAA\xDA\xF5\xDE\x70\x40\x09\xF5";

	auto translated_pinblock = binary_pin->translate(pan, pinblock).value();
	EXPECT_STREQ(translated_pinblock.c_str(), expected_pinblock.c_str());
}

