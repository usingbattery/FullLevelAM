#pragma once
#include"Point3D.h"
namespace nsp {

    class Ray {
    public:
        Point3D P;
        Vector3D V;

        Ray(Point3D p, Vector3D v);

        std::string toString();

        bool operator==(Ray ray);

        bool operator!=(Ray ray);
    };
}