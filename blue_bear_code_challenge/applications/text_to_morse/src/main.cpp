//////////////////////////////////////////////////////////////////
//  main.cpp
//
//  Created on: 23 Apr 2018
//  Author: Sundev Pabla
//
//  Description: Entry point into text to morse conversion program
//////////////////////////////////////////////////////////////////
#include <iostream>
#include "file_encode_decode.h"
#include "text_to_morse_algorithm.h"

int main(int argc,char *argv[])
{
	static const int EXPECTED_ARGS = 3;

	if (argc >= EXPECTED_ARGS)
	{
		// Create instance of TextToMorseAlgorithm class
		EncodeDecodeAlgorithms::TextToMorseAlgorithm theTextToMorseAlgorithm;

		// Create instance of FileEncodeDecode class, the algorithm
		// to use for the Text to Morse conversion is passed in as an argument
		// along with the path to the file which is being converted
		FileEncodeDecode theFileEncodeDecode(theTextToMorseAlgorithm,argv[1],argv[2]);

		theFileEncodeDecode.process();
	}
	else
	{
		std::cout << "Error:  Insufficient Arguments";
	}

	return 0;

}




