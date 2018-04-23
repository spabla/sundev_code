//////////////////////////////////////////////////////////////////
//  main.cpp
//
//  Created on: 23 Apr 2018
//  Author: Sundev Pabla
//
//  Description: Entry point into text to morse conversion program
//////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file_encode_decode.h"

int main(int argc,char *argv[])
{


	// Create instance of TextToMorseAlgorithm class

	// Create instance of FileEncodeDecode class, the algorithm
	// to use for the Text to Morse conversion is passed in as an argument
	// along with the path to the file which is being converted
	std::cout << argv[0] << std::endl;
	std::cout << argv[1] << std::endl;

	std::ifstream infile(argv[1]);

	std::string line;
	while (std::getline(infile, line))
	{
		std::cout << line << std::endl;

	}

	FileEncodeDecode theFileEncodeDecode;

	return 0;

}




