#include "gtest/gtest.h"
#include "cipher.h"

#include <memory>

class test_mac: public ::testing::Test {
protected:
	std::unique_ptr<ISO8583::mac> ascii_mac = { nullptr };
	std::unique_ptr<ISO8583::mac> binary_mac = { nullptr };
public:
	void SetUp() {
		ascii_mac = ISO8583::cipher::make_mac(ISO8583::message_type::ascii);
		binary_mac = ISO8583::cipher::make_mac(ISO8583::message_type::binary);
	}

	void TearDown() {
	}
};

// unit test ascii message
TEST_F(test_mac, ascii_generation) {

	std::string message = "Hello World!";
	std::string expected_mac = "8E6F71A9";

	auto generated_mac = ascii_mac->generate(message).value();
	EXPECT_STREQ(generated_mac.c_str(), expected_mac.c_str());

}

TEST_F(test_mac, ascii_verification) {

	std::string message = "Hello World!";
	std::string message_mac = "8E6F71A9";

	EXPECT_TRUE(ascii_mac->verify(message, message_mac));
}

 // unit test binary message
TEST_F(test_mac, binary_generation) {

	std::string message = "Hello World!";
	std::string expected_mac = "\x38\x45\x36\x46\x37\x31\x41\x39";

	auto generated_mac = binary_mac->generate(message).value();
	EXPECT_STREQ(generated_mac.c_str(), expected_mac.c_str());
}

 TEST_F(test_mac, binary_verification) {

	 std::string message = "Hello World!";
	 std::string message_mac = "\x38\x45\x36\x46\x37\x31\x41\x39";

	 EXPECT_TRUE(ascii_mac->verify(message, message_mac));

 }

