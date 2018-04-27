///////////////////////////////////////////////////////////////////////////
// morse_to_text_algorithm.h
//
//  Created on: 23 Apr 2018
//  Author: Sundev Pabla
//
//  Description: The specification for the morse to text algorithm class
///////////////////////////////////////////////////////////////////////////

#ifndef MORSE_TO_TEXT_ALGORITHM_H_
#define MORSE_TO_TEXT_ALGORITHM_H_

#include "encode_decode_algorithm_interface.h"
#include <string>
#include "morse_char_encode_decode.h"

namespace EncodeDecodeAlgorithms
{
	// This class is responsible for reading in a morse code file and doing
	// the conversion necessary to write out a text file
	class MorseToTextAlgorithm : public EncodeDecodeAlgorithmInterface
	{
	public:

		// Constructor
		MorseToTextAlgorithm()
		{
			// Nothing to construct
		}

		// Overridden function which must be implemented by
		// this class in order to provide the algorithm for converting
		// morse to text
		bool encodeDecodeLine(std::string& theLine);
	private:
		// Utility class used for decoding characters from morse string to text
		Utilities::MorseCharEncodeDecode m_morse_to_char_decoder;

	};
}



#endif /* MORSE_TO_TEXT_ALGORITHM_H_ */
