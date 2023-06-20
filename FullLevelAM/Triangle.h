#pragma once

#include <vector>
#include "Point3D.h"

namespace nsp {

    class Triangle {

    public:

        Triangle() {}

        Triangle(Point3D a, Point3D b, Point3D c, Vector3D vec_3d = Vector3D(0, 0, 0)) : A(a), B(b), C(c), N(vec_3d) {}

        std::string toString();

        double zMinPnt();

        double zMaxPnt();

        //Three vertices of a triangular row
        Point3D A;
        Point3D B;
        Point3D C;
        //Normal vector of triangle
        Vector3D N;

        bool operator==(Triangle t);

        bool operator!=(Triangle t);
    private:

    };
}
