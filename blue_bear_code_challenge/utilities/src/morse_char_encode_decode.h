///////////////////////////////////////////////////////////////////////////
// morse_char_encode_decode.h
//
//  Created on: 23 Apr 2018
//  Author: Sundev Pabla
//
//  Description: The specification for the class which converts characters to morse string
//               and morse string to characters
///////////////////////////////////////////////////////////////////////////

#ifndef MORSE_CHAR_ENCODE_DECODE_H_
#define MORSE_CHAR_ENCODE_DECODE_H_

#include <iostream>
#include <sstream>
#include <string.h>
#include "basic_types.h"
#include <map>

namespace Utilities
{
	// This class converts characters to morse string
    // and morse string to characters
	class MorseCharEncodeDecode
	{
	public:

		MorseCharEncodeDecode();

		// A function which returns the morse string for the character
		// passed in.  If the character is not found a null string is returned
		std::string getMorseString(char theCharacter);

		// Analyses the significant bits in a byte to determine the text character
		// represented by the morse byte.  A 1 in the byte represents a dot in
		// the character and a 0 represents a dash.  If the morse string is not
		// identified then a null string is returned.
		std::string getTextChar(Uint8_t theMorseCharByte,
					            Uint8_t numberOfSignificantBitsInByte);

	private:

		// Arrays for storing morse strings for letters
		std::string m_morse_row_one[2];
		std::string m_morse_row_two[4];
		std::string m_morse_row_three[8];
		std::string m_morse_row_four[16];

		std::map<char,std::string> m_number_and_symbol_map_to_morse;
		std::map<std::string,char> m_number_and_symbol_map_from_morse;

	};
}

#endif /* MORSE_CHAR_ENCODE_DECODE_H_ */
