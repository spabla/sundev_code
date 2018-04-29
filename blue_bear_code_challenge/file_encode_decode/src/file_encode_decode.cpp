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
	 else
	 {
		 // Only attempt to open / create output file if input file was
		 // successfully opened.
		 if(!m_output_file_stream)
		 {
		    std::cout << "Cannot open output file.\n";
		 }
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
		// Holds a line from the file
		std::string line;

		// Loop through the entire file handling a line at a time
		// Note: The entire file is not being read into a buffer, in
		// case a large file causes memory issues with a limited stack
		while (std::getline(m_input_file_stream, line))
		{
			// Pass the line to the encode / decode algorithm
			m_encode_decode_algorithm.encodeDecodeLine(line);
			// Write the modified line to file
			m_output_file_stream << line << std::endl;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////


