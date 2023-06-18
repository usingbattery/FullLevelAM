#include <iostream>
#include <fstream>
#include "File.h"

namespace nsp {

    //open file at begining
    File::File(std::string filepath) {
        this->infile.open(filepath, std::ios::in);
        this->outfile.open(filepath, std::ios::app);
    }

    //close file at the end
    File::~File() {
        infile.close();
        outfile.close();
    }

    //write text into filePath.txt
    void File::write(std::string text) {
        outfile << text;
    }

    //read text and return hasLeft
    bool File::read(std::string *text) {
        if (infile >> *text) {
            return true;
        }
        else {
            return false;
        }
    }
}