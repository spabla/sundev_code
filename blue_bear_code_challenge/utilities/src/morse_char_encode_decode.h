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
		std::string getMorseString(char theCharacter);

	private:

		std::string m_morse_row_one[2];
		std::string m_morse_row_two[4];
		std::string m_morse_row_three[8];
		std::string m_morse_row_four[16];

	};
}





#endif /* MORSE_CHAR_ENCODE_DECODE_H_ */
