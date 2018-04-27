/////////////////////////////////////////////
//  File Name: text_to_morse_algorithm.cpp
//
//  Created on: 23 Apr 2018
//  Author: Sundev Pabla
/////////////////////////////////////////////
#include "text_to_morse_algorithm.h"
#include "basic_types.h"
#include <stdio.h>

namespace EncodeDecodeAlgorithms
{
	bool TextToMorseAlgorithm::encodeDecodeLine(std::string& theLine)
	{
		// Variable to hold the morse line which we will use to overwrite
		// the original line at the end
		std::string theMorseLine;

		// Loop through each character in the string
		for (std::string::iterator it = theLine.begin(),end = theLine.end(); it != end; ++it)
		{

			if (*it == SINGLE_SPACE_CHAR)
			{
				// We will assume this space is a space between words
				// and output four spaces.  Note that we have already
				// output three spaces at the end of the character thus
				// giving the total of seven spaces required between morse words
				static const std::string FOUR_SPACES = "    ";
				theMorseLine += FOUR_SPACES;
			}
			else
			{
				theMorseLine += m_char_to_morse_encoder.getMorseString(*it);
				theMorseLine += SPACING_BETWEEN_MORSE_CHARACTERS;
			}

		}

		// Now overwrite the original line with the Morse Line
		theLine = theMorseLine;

		return true;
	}
}


