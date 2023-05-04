#include <iostream>
#include <fstream>
#include "File.h"
namespace nsp {
	//open file at begining
	File::File(std::string filepath) {
		FilePath = filepath;
		infile.open(FilePath, std::ios::in);
	}

	File::~File() {
		closeFile();
		infile.close();
	}

	//write text into filePath.txt
	void File::write(std::string text) {
		/*if (!outfile)
		{
			std::cout << "file not open!" << std::endl;
			exit(1);
		}*/
		outfile.open(FilePath, std::ios::app);
		outfile << text << std::endl;
		closeFile();
	}

	//close file at the end
	void File::closeFile() {
		outfile.close();
	}

	void File::clear() {
		closeFile();
		std::fstream tmp_outfile;
		tmp_outfile.open(FilePath, std::ios::out);
		outfile.open(FilePath, std::ios::app);
	}

}