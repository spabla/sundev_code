///////////////////////////////////////////////////////////////////////////
//  file_encode_decode.h
//
//  Created on: 23 Apr 2018
//  Author: Sundev Pabla
//
//  Description: The specification for the file encode decode class
///////////////////////////////////////////////////////////////////////////

#ifndef FILE_ENCODE_DECODE_H_
#define FILE_ENCODE_DECODE_H_

#include <fstream>

// Forward declarations
namespace EncodeDecodeAlgorithms
{

	class EncodeDecodeAlgorithmInterface;
}

class FileEncodeDecode
{
public:
	// Constructor
	FileEncodeDecode(EncodeDecodeAlgorithms::EncodeDecodeAlgorithmInterface& theEncodeDecodeAlgorithm,
					std::string theInputFile,
					std::string theOutputFile);
	// Destructor
	~FileEncodeDecode();

	// Process function is called to process the input file
	// by reading in a line of data. The line is then processed
	// by the EncodeDecodeAlgorithm and then written out to an output
	// file
	void process();
private:

	// Reference to the algorithms which should be used for the encode decode
	EncodeDecodeAlgorithms::EncodeDecodeAlgorithmInterface& m_encode_decode_algorithm;

	// The input file stream
	std::ifstream m_input_file_stream;
	// The output file stream
	std::ofstream m_output_file_stream;

};

#endif /* FILE_ENCODE_DECODE_H_ */
