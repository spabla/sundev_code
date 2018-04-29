//============================================================================
// Name        : test_suite_morse_encode_decode.cpp
// Author      : Sundev Pabla
// Version     :
// Copyright   : 
// Description : This is a test harness for the purpose of testing the morse encode
//               and decode software.
//============================================================================

#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include "basic_types.h"
#include "text_to_morse_algorithm.h"
#include "morse_to_text_algorithm.h"
#include "file_encode_decode.h"


enum PassFail_t
{
	FAIL,
	PASS,
};

// Function Prototypes
PassFail_t Test1_ObjectCreation();
PassFail_t Test2_EncodeDecodeFile();
void PerformEncodeDecode();


int main()
{
	int testPassCount = 0;
	int testFailCount = 0;

	// Run tests
	Test1_ObjectCreation() == PASS ? testPassCount++:testFailCount++;
	Test2_EncodeDecodeFile() == PASS ? testPassCount++:testFailCount++;

	std::cout <<"Tests Passed: " << testPassCount << std::endl;
	std::cout <<"Tests Failed: " << testFailCount << std::endl;

	std::cout <<"Press any key to exit" << std::endl;

	std::cin.get();

	return 0;
}

PassFail_t Test1_ObjectCreation()
{
	// This function confirms that even the passing of nonsensical paths does not cause crash
	EncodeDecodeAlgorithms::TextToMorseAlgorithm theEncodeAlgorithm;
	EncodeDecodeAlgorithms::MorseToTextAlgorithm theDecodeAlgorithm;

	FileEncodeDecode theFileEncode(theEncodeAlgorithm,"anyString","anyString");
	FileEncodeDecode theFileDecode(theDecodeAlgorithm,"anyString","anyString");

	return PASS;
}

PassFail_t Test2_EncodeDecodeFile()
{
	// Initialise to Fail
	PassFail_t theResult = FAIL;

	PerformEncodeDecode();

	// Now confirm successful encode decode
	std::ifstream theInputFile("./TestFiles/testFileHelloWorld.txt");
	std::ifstream theOutputFile("./TestFiles/testFileHelloWorldReverse.txt");

	std::string lineIn;
	std::string lineOut;

	std::getline(theInputFile, lineIn);
	std::getline(theOutputFile, lineOut);

	std::transform(lineIn.begin(), lineIn.end(),lineIn.begin(), ::toupper);

	if (lineIn.compare(lineOut) == 0)
	{
		theResult = PASS;
	}

	return theResult;
}

void PerformEncodeDecode()
{
	EncodeDecodeAlgorithms::TextToMorseAlgorithm theEncodeAlgorithm;
	EncodeDecodeAlgorithms::MorseToTextAlgorithm theDecodeAlgorithm;

	FileEncodeDecode theFileEncode(theEncodeAlgorithm,
									"./TestFiles/testFileHelloWorld.txt",
									"./TestFiles/testFileHelloWorld.morse");
	theFileEncode.process();
	FileEncodeDecode theFileDecode(theDecodeAlgorithm,
									"./TestFiles/testFileHelloWorld.morse",
									"./TestFiles/testFileHelloWorldReverse.txt");
	theFileDecode.process();
}
