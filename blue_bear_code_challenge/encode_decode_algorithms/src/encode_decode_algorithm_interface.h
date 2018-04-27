///////////////////////////////////////////////////////////////////////////
//  encode_decode_algorithm_interface.h
//
//  Created on: 23 Apr 2018
//  Author: Sundev Pabla
//
//  Description: The specification for the encode decode interface class
///////////////////////////////////////////////////////////////////////////

#ifndef ENCODE_DECODE_ALGORITHM_INTERFACE_H_
#define ENCODE_DECODE_ALGORITHM_INTERFACE_H_

#include <iostream>
#include <sstream>
#include <string.h>

namespace EncodeDecodeAlgorithms
{

	static const std::string SPACING_BETWEEN_MORSE_WORDS = "       ";
	static const std::string SPACING_BETWEEN_MORSE_CHARACTERS = "   ";
	static const std::string SINGLE_SPACE = " ";
	static const char SINGLE_SPACE_CHAR = ' ';

	// This is an abstract class which defines an
	// interface which all EncodeDecodeAlgorithm classes
	// inheriting from this class must implement
	class EncodeDecodeAlgorithmInterface
	{
	public:
		EncodeDecodeAlgorithmInterface()
		{
			// Nothing to construct
		}

		virtual ~EncodeDecodeAlgorithmInterface()
		{
			// Nothing to destroy
		}

		// Pure virtual function which all classes implementing
		// the interface must override.  Each concrete class will
		// provide its own algorithm for handling the line.
		virtual bool encodeDecodeLine(std::string& theLine) = 0;

	};
}

#endif /* ENCODE_DECODE_ALGORITHM_INTERFACE_H_ */
