#pragma once
#include"Point3D.h"
namespace nsp {
    class Line {
    public:
        Point3D p;
        Vector3D v;

        Line(Point3D p = Point3D(), Vector3D v = Vector3D());

        std::string toString();

        bool operator==(Line line);

        bool operator!=(Line line);
    };
}
