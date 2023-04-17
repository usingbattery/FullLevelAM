#include "GCode.h"
#include "Point3D.h"

using namespace gcode;
using namespace point3d;

int main() {

    Point3D p = Point3D(1, 2, 3, 4);
    std::cout << p.toString();

//    std::string filePathIOS = "~/Desktop/CLion/FullLevelAM/FullLevelAM/GCode.txt";
//    std::string filePathWin = "GCode.txt";
//    openFile(filePathWin);
//    G00(1, 1, 1, 100);
//    G01(1, 2, 3, 100);
//    G00(1, 1, doubleNull, 100);
//    G02(17, 1, 2, 3, 5, 1000);
//    closeFile();
}
