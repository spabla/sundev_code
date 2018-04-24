////////////////////////////////////////////////////////////////////////////
//  text_to_morse_algorithm.h
//
//  Created on: 23 Apr 2018
//  Author: Sundev Pabla
//
//  Description: The specification for the text to morse algorithm class
///////////////////////////////////////////////////////////////////////////

#ifndef TEXT_TO_MORSE_ALGORITHM_H_
#define TEXT_TO_MORSE_ALGORITHM_H_

#include "encode_decode_algorithm_interface.h"
#include <string>

namespace EncodeDecodeAlgorithms
{
	// This class is responsible for reading in a text file and doing
	// the conversion necessary to write out a morse file
	class TextToMorseAlgorithm : public EncodeDecodeAlgorithmInterface
	{
	public:
		TextToMorseAlgorithm()
		{

		}

	};
}



#endif /* TEXT_TO_MORSE_ALGORITHM_H_ */
