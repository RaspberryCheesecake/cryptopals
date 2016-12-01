#include "hex_to_base64_encode.c"
#define CATCH_CONFIG_MAIN // creates a main() where the tests are run
#include "catch.hpp"

TEST_CASE("Single hex char turns into appropriate padded byte") {
	const char test_char = 'a';
	uint8_t result_byte = 0x0a;
	REQUIRE(HexCharToByte(test_char) == result_byte);
}

TEST_CASE("Every hex char turns into the appropriate padded byte") {
	const char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	const char lowers[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	const char uppers[] = {'A', 'B', 'C', 'D', 'E', 'F'};
	const char rubbish[] = {'!', '=', '+', '?', '[', '}'};
	
	for (int i = 0; i < 6; i++) {
        REQUIRE( HexCharToByte(lowers[i]) == i + 10 );
        REQUIRE( HexCharToByte(uppers[i]) == i + 10 );
        REQUIRE( HexCharToByte(rubbish[i]) == 0x00 );
	}
	
	for (int i = 0; i < 10; i++) {
		REQUIRE( HexCharToByte(numbers[i]) == i );
	}

}

TEST_CASE("Hex representation in pair of char is correctly converted to single byte") {
	const char test_char_pair[] = {'a', 'b'};
	REQUIRE(HexCharPairToBytes(test_char_pair) == 0xba);
}

TEST_CASE("Hex represenation of series of char values is correctly converted to bytes") {
	//const char* test_saying = 'deadbeef11';
	
}
