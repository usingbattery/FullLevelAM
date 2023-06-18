#pragma once

#include <iostream>
#include <fstream>

namespace nsp {

	class File {

	public:

		//open file at begining
		File(std::string filepath = "");

		//close file at the end
		~File();

		//write text into filePath.txt
		void write(std::string text);

		bool read(std::string* text);

		//not a method
		//should realize in File()
		//void clear();

	private:

		//avoid open and close each time write()
		std::ofstream outfile;

		//read file
		std::ifstream infile;
	};
}