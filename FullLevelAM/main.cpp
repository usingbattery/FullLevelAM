#include "GCode.h"
using namespace gcode;


int main() {
    std::string filePath="~/Desktop/CLion/FullLevelAM/FullLevelAM/GCode.txt";
    openFile(filePath);
//    write(doubleToString(12.123, 2));
    G00(1, 1, 1, 100);
    G01(1, 2, 3, 100);
    G00(1, 1, doubleNull, 100);
    G02(17, 1, 2, 3, 5, 1000);
    closeFile();
}
