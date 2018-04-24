///////////////////////////////////////////////////////////////////////////
//  file_encode_decode.cpp
//
//  Created on: 23 Apr 2018
//  Author: Sundev Pabla
//
//  Description: The implementation for the File Encode Decode class
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include "file_encode_decode.h"
#include "encode_decode_algorithm_interface.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////

FileEncodeDecode::FileEncodeDecode(EncodeDecodeAlgorithms::EncodeDecodeAlgorithmInterface& theEncodeDecodeAlgorithm,
		std::string theInputFile,
		std::string theOutputFile):m_encode_decode_algorithm(theEncodeDecodeAlgorithm),
		m_input_file_stream(theInputFile.c_str()),
		m_output_file_stream(theOutputFile.c_str())
{
	 // Write error to file if either input or output file cannot be opened
	 if(!m_input_file_stream)
	 {
	    std::cout << "Cannot open input file.\n";
	 }


	 if(!m_output_file_stream)
	 {
	    std::cout << "Cannot open output file.\n";
	 }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

FileEncodeDecode::~FileEncodeDecode()
{
	// Close down the files
	if(m_input_file_stream)
	{
		m_input_file_stream.close();
	}

	if(m_output_file_stream)
	{
		m_output_file_stream.close();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

void FileEncodeDecode::process()
{

	if((m_input_file_stream) && (m_output_file_stream))
	{
		std::string line;

		while (std::getline(m_input_file_stream, line))
		{
			std::cout << line << std::endl;
			m_output_file_stream << line << std::endl;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////


