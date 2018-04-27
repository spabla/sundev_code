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

			if (*it == SINGLE_SPACE_CHAR)
			{
				// Increment the count of consecutive spaces
				countOfConsecutiveSpaces++;
				// As soon as the space count goes over 4
				// output a finger space
				if (countOfConsecutiveSpaces == 5)
				{
					theTextLine += SINGLE_SPACE;
				}
			}
			else
			{
				// Not a space, so zero the consecutive spaces count
				countOfConsecutiveSpaces = 0;
			}
			theTextLine += m_morse_to_char_encoder.getTextChar(theMorseCharByte);
		}

		// Now overwrite the original line with the Morse Line
		theLine = theTextLine;

		return true;
	}
}






