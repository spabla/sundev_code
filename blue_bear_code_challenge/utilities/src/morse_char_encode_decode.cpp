///////////////////////////////////////////////////////////////////////////////////////////
// morse_char_encode_decode.cpp
//
//  Created on: 23 Apr 2018
//  Author: Sundev Pabla
//
//  Description: The implementation for the class which converts characters to morse string
//               and morse string to characters
////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "morse_char_encode_decode.h"

namespace Utilities
{
	// Store the morse binary tree in char arrays
	// Note that consideration was given to the use of map from the standard template library
	// However a map is sorted alphabetically, this would have meant that the advantage of
	// morse code where the most frequently used letters appear first would have been lost

	// A space is used where a character is not supported
	static const Uint8_t ELEMENTS_ON_ROW_ONE = 2U;
	static const char charRowOne[ELEMENTS_ON_ROW_ONE] = {'E','T'};
	static const Uint8_t ELEMENTS_ON_ROW_TWO = 4U;
	static const char charRowTwo[ELEMENTS_ON_ROW_TWO] = {'I','A','N','M'};
	static const Uint8_t ELEMENTS_ON_ROW_THREE = 8U;
	static const char charRowThree[ELEMENTS_ON_ROW_THREE] = {'S','U','R','W','D','K','G','O'};
	static const Uint8_t ELEMENTS_ON_ROW_FOUR = 16U;
	static const char charRowFour[ELEMENTS_ON_ROW_FOUR] = {'H','V','F','U','L','A','P','J','B','X','C','Y','Z','Q',' ',' '};

	static const Uint8_t START_ROW = 1;
	static const Uint8_t TOTAL_ROW = 4;

	static const std::string DOT = ".";
	static const std::string DASH = "-";
	static const std::string SPACE = " ";

	MorseCharEncodeDecode::MorseCharEncodeDecode()
	{
		// Populate arrays with strings of morse constants

		// Loop rows 1, 2, 3 and 4
		for (Uint8_t row = START_ROW; row <= TOTAL_ROW; row++)
		{

			// Populate array positions 0 to 15
			for (Uint8_t i = 0; i < pow(2,row); i++ )
			{

				// For even i output dot, for odd i output dash
				switch (row)
				{
				case 1:
					((i%2) == 0) ? m_morse_row_one[i] = DOT :
							        m_morse_row_one[i] = DASH;
					break;
				case 2:
					((i%2) == 0) ? m_morse_row_two[i] = m_morse_row_one[i/2] + SPACE + DOT :
									m_morse_row_two[i] = m_morse_row_one[i/2] + SPACE +DASH;
					break;
				case 3:
					((i%2) == 0) ? m_morse_row_three[i] = m_morse_row_two[i/2] + SPACE +DOT :
									m_morse_row_three[i] = m_morse_row_two[i/2] + SPACE +DASH;
					break;
				case 4:
					((i%2) == 0) ? m_morse_row_four[i] = m_morse_row_three[i/2] + SPACE +DOT :
									m_morse_row_four[i] = m_morse_row_three[i/2] + SPACE +DASH;
					break;
				}

			}
		}
	}

	//=============================================================================

	std::string MorseCharEncodeDecode::getMorseString(char theCharacter)
	{
		// Boolean gets set true when character found
		bool characterFound = false;
		// The return value
		std::string theMorseString;

		// Our code only checks for upper case characters
		// so ensure uppercase
	    if(islower(theCharacter))
	    {
	    	theCharacter = toupper(theCharacter);
	    }

		for (Uint8_t row = START_ROW; row <= TOTAL_ROW; row++)
		{
			// Populate array positions 0 to 15
			for (Uint8_t i = 0; i < pow(2,row); i++ )
			{
				switch (row)
				{
				case 1:
					if (theCharacter == charRowOne[i])
					{
						characterFound = true;
						theMorseString = m_morse_row_one[i];
					}
					break;
				case 2:
					if(theCharacter == charRowTwo[i])
					{
						characterFound = true;
						theMorseString = m_morse_row_two[i];
					}
					break;
				case 3:
					if(theCharacter == charRowThree[i])
					{
						characterFound = true;
						theMorseString = m_morse_row_three[i];
					}
					break;
				case 4:
					if(theCharacter == charRowFour[i])
					{
						characterFound = true;
						theMorseString = m_morse_row_four[i];
					}
					break;
				}

				// Exit loop if character found
				if (characterFound == true)
				{
					break;
				}
			}
			// Exit loop if character found
			if (characterFound == true)
			{
				break;
			}
		}

		return theMorseString;
	}

	//============================================================================================

}



