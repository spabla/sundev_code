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

namespace Utilities
{
	// This class converts characters to morse string
    // and morse string to characters
	class MorseCharEncodeDecode
	{
	public:

		MorseCharEncodeDecode();

		// A function which returns the morse string for the character
		// passed in
		static std::string getMorseString(char theCharacter);

	private:

		static std::string m_morse_row_one[2];
		static std::string m_morse_row_two[4];
		static std::string m_morse_row_three[8];
		static std::string m_morse_row_four[16];

		static std::string getMorseString(int row, int col);
	};
}





#endif /* MORSE_CHAR_ENCODE_DECODE_H_ */
