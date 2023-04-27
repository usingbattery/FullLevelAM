#include <iostream>
#include <fstream>
#include "File.h"

//open file at begining
File::File(std::string filePath) {
	outfile.open(filePath, std::ios::app);
}

//write text into filePath.txt
void File::write(std::string text) {
	/*if (!outfile)
	{
		std::cout << "file not open!" << std::endl;
		exit(1);
	}*/
	outfile << text;
}

//close file at the end
void File::closeFile() {
	outfile.close();
}