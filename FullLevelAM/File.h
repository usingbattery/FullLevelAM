#pragma once

#include <iostream>
#include <fstream>

class File {

public:

	//open file at begining
	File(std::string filePath);

	//write text into filePath.txt
	void write(std::string text);

	//close file at the end
	void closeFile();

private:

	//avoid open and close each time write()
	std::ofstream outfile;
};