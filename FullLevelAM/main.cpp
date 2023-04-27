#include "File.h"
#include "Point3D.h"
using namespace nsp;
int main() {

    File tmp;

    tmp.write("text1");
    tmp.write("text2");
    std::string s1, s2;
//    std::string s2;
    std::getline(tmp.infile, s1);
    std::cout << s1 << std::endl;
    std::getline(tmp.infile, s2);
    std::cout << s2 << std::endl;
//    tmp.clear();
//    std::getline(tmp.infile, s);
//    std::cout << s << std::endl;
//    Point3D p = Point3D(1, 2, 3, 4);
//    std::cout << p.toString();

//    std::string filePathIOS = "~/Desktop/CLion/FullLevelAM/FullLevelAM/GCode.txt";
//    std::string filePathWin = "GCode.txt";
//    openFile(filePathWin);
//    G00(1, 1, 1, 100);
//    G01(1, 2, 3, 100);
//    G00(1, 1, doubleNull, 100);
//    G02(17, 1, 2, 3, 5, 1000);
//    closeFile();
}
