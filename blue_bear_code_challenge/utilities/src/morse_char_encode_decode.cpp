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

namespace Utilities
{
	// Store the morse binary tree in char arrays
	// Note that consideration was given to the use of map from the standard template library
	// However a map is sorted alphabetically, this would have meant that the advantage of
	// morse code where the most frequently used letters appear first would have been lost

	// A space is used where a character is not supported
	static const char charRowOne[2] = {'E','T'};
	static const char charRowTwo[4] = {'I','A','N','M'};
	static const char charRowThree[8] = {'S','U','R','W','D','K','G','O'};
	static const char charRowFour[16] = {'H','V','F','U','L','A','P','J','B','X','C','Y','Z','Q',' ',' '};


	MorseCharEncodeDecode::MorseCharEncodeDecode()
	{
		// Populate arrays with strings of morse constants

		static const int START_ROW = 1;
		static const int TOTAL_ROW = 4;

		static const std::string DOT = ".";
		static const std::string DASH = "-";
		static const std::string SPACE = " ";

		// Loop rows 1, 2, 3 and 4
		for (int row = START_ROW; row <= TOTAL_ROW; row++)
		{

			// Populate array positions 0 to 15
			for (int i = 0; i < pow(2,row); i++ )
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

	}

	//============================================================================================



	//========================================================================================
	void MorseCharEncodeDecode::getMorseString(int row, int col)
	{


	}
}



