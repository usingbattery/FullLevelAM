//
// Created by MBP on 2023/4/18.
//

#ifndef GCODE_TRIANGLE_H
#define GCODE_TRIANGLE_H
#include <vector>
#include "Point3D.h"

namespace nsp {

    class Triangle {
    public:

        Triangle() {}

        Triangle(Point3D a, Point3D b, Point3D c, Vector3D vec_3d = Vector3D(0, 0, 0)) : A(a), B(b), C(c), N(vec_3d) {}

        double zMinPnt();

        double zMaxPnt();

        //Three vertices of a triangular row
        Point3D A;
        Point3D B;
        Point3D C;
        //Normal vector of triangle
        Vector3D N;
        //The layer height contained in the storage patch
        std::vector<int> zs;

        bool operator==(Triangle t);

        bool operator!=(Triangle t);
    private:

    };
}

#endif //GCODE_TRIANGLE_H
