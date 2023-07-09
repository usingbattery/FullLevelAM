#pragma once

#include "Matrix3D.h"

namespace nsp {

    class Vector3D {

    public:
        double dx;
        double dy;
        double dz;

        Vector3D(double dx = 0, double dy = 0, double dz = 0);

        std::string toString();

        Vector3D clone();

        void reverse();

        Vector3D reversed();

        double dotProduct(Vector3D vec);

        Vector3D crossProduct(Vector3D vec);

        void amplify(double f);

        Vector3D amplified(double f);

        double lengthSquare();

        double length();

        void normalize();

        Vector3D normalized();

        bool isZeroVector();

        Vector3D multiplied(Matrix3D m);

        bool isParallel(Vector3D other);

        double getAngle(Vector3D vec);

        Vector3D getOrthoVector2D();

        double getAngle2D(Vector3D vec);

        Vector3D operator+(Vector3D other);

        Vector3D operator-(Vector3D other);

        Vector3D operator*(Matrix3D m);

        bool operator==(Vector3D vector3D);

        bool operator!=(Vector3D vector3D);
    };
}