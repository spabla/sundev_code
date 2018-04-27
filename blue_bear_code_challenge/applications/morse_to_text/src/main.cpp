//////////////////////////////////////////////////////////////////////
//  main.cpp
//
//  Created on: 23 Apr 2018
//  Author: Sundev Pabla
//
//  Description: Entry point into morse to text conversion program
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include "file_encode_decode.h"
#include "morse_to_text_algorithm.h"
#include "basic_types.h"

int main(int argc,char *argv[])
{
	// The number of commandline arguments expected
	// 1st is path to application which is automatically passed in
	// 2nd is path to the input file
	// 3rd is path and name of the output file
	static const Uint8_t EXPECTED_ARGS = 3;

	if (argc >= EXPECTED_ARGS)
	{
		// Create instance of MorseToTextAlgorithm class
		EncodeDecodeAlgorithms::MorseToTextAlgorithm theMorseToTextAlgorithm;

		// Create instance of FileEncodeDecode class, the algorithm
		// to use for the Morse to Text conversion is passed in as an argument
		// along with the path to the file which is being converted
		FileEncodeDecode theFileEncodeDecode(theMorseToTextAlgorithm,argv[1],argv[2]);

		// Let the processing of the file begin
		theFileEncodeDecode.process();
	}
	else
	{
		std::cout << "Error:  Insufficient Arguments";
	}

	return 0;

}

