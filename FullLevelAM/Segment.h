#pragma once
#include"Point3D.h"
namespace nsp {

    class Segment {

    public:
        Point3D A;
        Point3D B;

        Segment(Point3D a = Point3D(), Point3D b = Point3D());

        std::string toString();

        double length();

        Vector3D direction();

        void swap();

        bool operator==(Segment segment);

        bool operator!=(Segment segment);
    };
}