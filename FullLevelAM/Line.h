#pragma once
#include"Point3D.h"

class Line {
public:
    Point3D p;
    Vector3D v;
    Line(Point3D p = Point3D(), Vector3D v = Vector3D());
};

