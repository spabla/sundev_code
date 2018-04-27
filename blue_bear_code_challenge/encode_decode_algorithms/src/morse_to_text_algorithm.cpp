///////////////////////////////////////////////////////////////////////////
//  morse_to_text_algorithm.cpp
//
//  Created on: 23 Apr 2018
//  Author: Sundev Pabla
//
//  Description: The specification for the morse to text algorithm class
///////////////////////////////////////////////////////////////////////////

#include "morse_to_text_algorithm.h"
#include "basic_types.h"
#include <stdio.h>

namespace EncodeDecodeAlgorithms
{
	bool MorseToTextAlgorithm::encodeDecodeLine(std::string& theLine)
	{
		// Variable to hold the text line which we will use to overwrite
		// the original line at the end
		std::string theTextLine;

		// Loop through each character in the string
		for (std::string::iterator it = theLine.begin(),end = theLine.end(); it != end; ++it)
		{
			// We need to keep a count of consecutive spaces
			// 1 space is a space between dots and dashes of the same character
			// 2, 3 or 4 consecutive spaces will be considered a space between characters
			// > 4 characters will be considered a space between words
			Uint8_t countOfConsecutiveSpaces = 0;
			static const Uint8_t MIN_SPACES_FOR_FINGER_SPACE = 5U;
			static const Uint8_t MAX_SPACE_IN_MORSE_CHAR = 1U;

			if (*it == SINGLE_SPACE_CHAR)
			{
				// Increment the count of consecutive spaces
				countOfConsecutiveSpaces++;
				// As soon as the space count goes over 4
				// output a finger space
				if (countOfConsecutiveSpaces == MIN_SPACES_FOR_FINGER_SPACE)
				{
					theTextLine += SINGLE_SPACE;
				}
			}
			else
			{
				// We will encode a byte with information about the morse character
				// a 1 in the byte will signify a dot and a 0 will signify a dash
				Uint8_t theMorseCharByte = 0U;
				Uint8_t numberOfSignificantBitsInByte = 0U;

				// If the count of spaces is greater than 1 and less than 5 then
				// assume the "theMorseCharByte" contains info on a complete morse
				// character.
				if ((countOfConsecutiveSpaces > MAX_SPACE_IN_MORSE_CHAR) &&
						(countOfConsecutiveSpaces > MIN_SPACES_FOR_FINGER_SPACE))
				{
					// You can't have more than 8 bits in a byte
					static const Uint8_t MAX_SIGNIFICANT_BITS_IN_BYTE = 8U;

					// We have a complete morse character encoded in the byte, lets decode it

					if (numberOfSignificantBitsInByte <= MAX_SIGNIFICANT_BITS_IN_BYTE)
					{
						theTextLine += m_morse_to_char_decoder.getTextChar(theMorseCharByte,
																		   numberOfSignificantBitsInByte);
					}
					else
					{
						std::cout << "ERROR - Too many dots and dashes in Morse character" << std::endl;
					}
					// zero theMorseCharByte and the number of significant bits it contains
					theMorseCharByte = 0U;
					numberOfSignificantBitsInByte = 0U;
				}

				// Zero the count of spaces
				countOfConsecutiveSpaces = 0U;

				// Encode the byte with information about the byte
				static const char DOT = '.';
				static const char DASH = '-';

				if (*it == DOT)
				{
					theMorseCharByte = theMorseCharByte << 1;
					theMorseCharByte = theMorseCharByte +1;
					numberOfSignificantBitsInByte++;
				}
				else if (*it == DASH)
				{
					theMorseCharByte = theMorseCharByte << 1;
					numberOfSignificantBitsInByte++;
				}
				else
				{
					std::cout << "Error - Unrecognised character in morse file, its not a dot, dash or space" <<std::endl;
					// We will ignore the character and carry on as if it was not there
				}
			}
		}

		// Now overwrite the original line with the Morse Line
		theLine = theTextLine;

		return true;
	}
}






