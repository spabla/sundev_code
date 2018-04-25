/////////////////////////////////////////////
//  File Name: text_to_morse_algorithm.cpp
//
//  Created on: 23 Apr 2018
//  Author: Sundev Pabla
/////////////////////////////////////////////
#include "text_to_morse_algorithm.h"

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
		    std::cout << "One character: " << *it << "\n";
		    *it = '*';
		}
		return true;
	}
}


