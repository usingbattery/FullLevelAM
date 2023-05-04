#pragma once

#include <iostream>
#include <fstream>

#define DEF clear()
namespace nsp {
    class File {

    public:

        //open file at begining
        File(std::string filepath = "C:\\CLion_txt\\text.txt");

        virtual ~File();

        //write text into filePath.txt
        void write(std::string text);

        //close file at the end
        void closeFile();

        //should realize in File() by std::ios::
        //clear file
        //void clear();

        //avoid open and close each time write()
        std::ofstream outfile;

        //read file
        std::ifstream infile;

        //path of file
        std::string FilePath;


    private:


    };
}