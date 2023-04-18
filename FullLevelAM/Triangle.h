//
// Created by MBP on 2023/4/18.
//

#ifndef GCODE_TRIANGLE_H
#define GCODE_TRIANGLE_H
#include <vector>
#include "nsp.h"
class Triangle {
public:
    Triangle(Point3D a, Point3D b, Point3D c, Vector3D vec_3d = Vector3D(0, 0, 0)): A(a), B(b), C(c), N(vec_3d){}
    double zMinPnt();
    double zMaxPnt();
private:
    //三角行的三个顶点
    Point3D A;
    Point3D B;
    Point3D C;
    //三角的法向量
    Vector3D N;
    //存储面片包含的层高
    std::vector<int> zs;
};


#endif //GCODE_TRIANGLE_H
