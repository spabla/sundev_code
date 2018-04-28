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

	//===========================================================================================

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

		// Numbers
		static const Uint8_t NUMBER_OF_NUMERIC_DIGITS = 10U;
		std::string morseNumberArray[NUMBER_OF_NUMERIC_DIGITS] = {
				"- - - - -",
				". - - - -",
				". . - - -",
				". . . - -",
				". . . . -",
				". . . . .",
				"- . . . .",
				"- - . . .",
				"- - - . .",
				"- - - - ."};

		char arrayOfNumericDigits[NUMBER_OF_NUMERIC_DIGITS] =
		{'0','1','2','3','4','5','6','7','8','9'};

		for (Uint8_t i = 0; i < NUMBER_OF_NUMERIC_DIGITS; i++)
		{
			m_number_and_symbol_map_to_morse[arrayOfNumericDigits[i]] = morseNumberArray[i];
			m_number_and_symbol_map_from_morse[morseNumberArray[i]] = arrayOfNumericDigits[i];
		}

		// Lets add some common symbols (eg. punctuation marks, @ symbol - want to be
		// able to handle email addresses) to the maps as well
		static const Uint8_t NUMBER_OF_SUPPORTED_SYMBOLS = 15;
		char arrayOfCommonSymbols[NUMBER_OF_SUPPORTED_SYMBOLS] =
		{
				'.', // fullstop
				',', // comma
				'?', // question mark
				'!', // exclamation mark
				'(', // open bracket
				')', // close bracker
				'&', // amphersand
				':', // colon
				';', // semi colon
				'=', // equals
				'+', // plus
				'-', // minus
				'"', // quotation mark
				'$', // dollar sign
				'@'// @ symbol
		};

		std::string arrayOfMorseStringsForCommonSymbols[NUMBER_OF_SUPPORTED_SYMBOLS] =
		{
				". - . - . -", // fullstop
				"- - . . - -", // comma
				". . - - . .", // question mark
				"- . - . - -", // exclamation mark
				"- . - - .", // open bracket
				"- . - - . -", // close bracker
				". - . . .", // amphersand
				"- - - . . .", // colon
				"- . - . - .", // semi colon
				"- . . . -", // equals
				". - . - .", // plus
				"- . . . . -", // minus
				". - . . - .", // quotation mark
				". . . -  . . -", // dollar sign
				". - - . - ."// @ symbol
		};

		for (Uint8_t i = 0; i < NUMBER_OF_SUPPORTED_SYMBOLS; i++)
		{
			m_number_and_symbol_map_to_morse[arrayOfCommonSymbols[i]] = arrayOfMorseStringsForCommonSymbols[i];
			m_number_and_symbol_map_from_morse[arrayOfMorseStringsForCommonSymbols[i]] = arrayOfCommonSymbols[i];
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

		// If we have not found the character then now check if it is a number or symbol
		if (characterFound == false)
		{
			// Create iterator for looking up in map
			std::map<char,std::string>::iterator it;
			it = m_number_and_symbol_map_to_morse.find(theCharacter);
			if (it != m_number_and_symbol_map_to_morse.end())
			{
				theMorseString = m_number_and_symbol_map_to_morse.find(theCharacter)->second;
			}
		}

		return theMorseString;
	}

	//============================================================================================

	std::string MorseCharEncodeDecode::getTextChar(Uint8_t theMorseCharByte,
						    					   Uint8_t numberOfSignificantBitsInByte)
	{
		// The return value
		std::string theReturnTextVal;

		// We will need to reconstruct the morse string
		// so that if it is not representative of a letter then
		// we can look it up in the map
		std::string theMorseString;

		// First remove the insignificant bits by shifting

		// You can't have more than 8 bits in a byte
		static const Uint8_t MAX_SIGNIFICANT_BITS_IN_BYTE = 8U;

		theMorseCharByte = theMorseCharByte << (MAX_SIGNIFICANT_BITS_IN_BYTE - numberOfSignificantBitsInByte);

		// Check for letters

			// Min array position of character
			Uint8_t minPossArrayPos = 0;
			// Max array position of character
			Uint8_t maxPossArrayPos = pow(2,numberOfSignificantBitsInByte)-1;


			// Now loop through the significant bits of the byte
			for (Uint8_t i = 0; i < numberOfSignificantBitsInByte; i++)
			{
				// Mask for checking if most significant bit is set
				static const Uint8_t MASK_FOR_CHECKING_MS_BIT = 0x80;
				Uint8_t numberOfPossValues = ((maxPossArrayPos+1)- minPossArrayPos);
				// Depending on whether we have a dot or dash we can throw away half these possible values
				if ((theMorseCharByte & MASK_FOR_CHECKING_MS_BIT) == MASK_FOR_CHECKING_MS_BIT)
				{
					// Bit set must be a dot
					// Reduce the number of possible values by reducing max possible value
					maxPossArrayPos = maxPossArrayPos - numberOfPossValues/2;
					theMorseString = theMorseString + DOT;
					// Don't put a space after last Dot
					if (i < numberOfSignificantBitsInByte-1)
					{
						theMorseString = theMorseString + SPACE;
					}
				}
				else
				{
					// must be a dash
					// Reduce the number of possible values by increasing min possible value
					minPossArrayPos = minPossArrayPos + numberOfPossValues/2;
					theMorseString = theMorseString + DASH;
					// Don't put a space after last Dash
					if (i < numberOfSignificantBitsInByte-1)
					{
						theMorseString = theMorseString + SPACE;
					}
				}

				// Shift the bit we have just checked out
				theMorseCharByte = theMorseCharByte << 1;
			}


			// At the end min and max end up the same, so it
			switch (numberOfSignificantBitsInByte)
			{
			case 1:
				theReturnTextVal = charRowOne[maxPossArrayPos];
				break;
			case 2:
				theReturnTextVal = charRowTwo[minPossArrayPos];
				break;
			case 3:
				theReturnTextVal = charRowThree[maxPossArrayPos];
				break;
			case 4:
				theReturnTextVal = charRowFour[minPossArrayPos];
				break;
			default:
				// Create iterator for looking up in map
				std::map<std::string,char>::iterator it;
				it = m_number_and_symbol_map_from_morse.find(theMorseString);

				if (it != m_number_and_symbol_map_from_morse.end())
				{
					theReturnTextVal = m_number_and_symbol_map_from_morse.find(theMorseString)->second;
				}
				break;
			}

		return theReturnTextVal;
	}
}



