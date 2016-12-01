#include <stdint.h> // for uint8_t single byte type
#include <stdio.h> // for input/output functions (writing to files etc)
#include <string.h> // for dealing with "" strings
#include <stdlib.h> // to use exit error codes

static uint8_t HexCharToByte(const char hex_char) {
	uint8_t padded_byte = 0;
	
	// ASCII char values are off by -0x09 for letters
	// eg 'a' is 0x41 and we want it to become a padded byte of 0x0a
	// Number char representations are OK though
	// eg '1' is 0x031, so we just need to mask out the front to get 0x01
	
	if (hex_char >= 'a' && hex_char <= 'f') {
		padded_byte = hex_char + 0x09;
	}
	
	else if (hex_char >= 'A' && hex_char <= 'F') {
		padded_byte = hex_char + 0x09;
	}
	
	else if (hex_char >= '0' && hex_char <= '9') {
		padded_byte = hex_char;
	}
	
	// then mask out the 4 leas significant bits, which we want to keep
	// by ANDing it with the bits 00001111
	uint8_t MASK = 0x0f;
	padded_byte = MASK & padded_byte;
	return padded_byte;
}

static uint8_t HexCharPairToBytes(const char* hex_char_pair) {
	int length = strlen(hex_char_pair);
	char hex_char_low = hex_char_pair[0];
	char hex_char_hi = hex_char_pair[1];
	
	if (length % 2 != 0) {
		printf("Input needs to be 2 characters of 1 byte each\n");
		printf("Your length is %x", length);
		exit(1);
	}
	
	// aw crap, it measures it to be 4? wat
	printf("Good, length is even at %x bytes long\n", length);
	
	// convert to padded bytes
	uint8_t first_part = HexCharToByte(hex_char_low);
	uint8_t second_part = HexCharToByte(hex_char_hi);
	printf("First part <%2x>, second part <%2x> \n", first_part, second_part);
	
	// now shift one of them up into the more significant Nybble ie by 4 bits
	second_part = second_part << 4;
	printf("Second part shifted <%2x> \n", second_part);
	
	// now add them together to squeeze the result into one byte
	uint8_t byte_value = first_part + second_part;
	
	return byte_value;
}
