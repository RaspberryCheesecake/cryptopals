#include "hex_to_base64_encode.c"
#define CATCH_CONFIG_MAIN // creates a main() where the tests are run
#include "catch.hpp"

TEST_CASE("Single hex char turns into appropriate padded byte") {
	const char test_char = 'a';
	uint8_t result_byte = 0x0a;
	REQUIRE(HexCharToByte(test_char) == result_byte);
}

TEST_CASE("Hex representation in chars is not converted to byte if not even") {
	const char test_char_pair[] = {'a', 'b'};
	REQUIRE(HexCharPairToBytes(test_char_pair) == 0xba);
}
