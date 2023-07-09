#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cfloat>
#include "Vector3D.h"
#include "Matrix3D.h"

namespace nsp {

    const double epsilon = DBL_EPSILON;
    const double epsilonSquare = epsilon* epsilon;

    class Point3D {

    public:

        double x;
        double y;
        double z;

        Point3D(double x = 0, double y = 0, double z = 0);

        std::string toString();

        Point3D clone();

        Vector3D pointTo(Point3D other);

        void translate(Vector3D vec);

        Point3D translated(Vector3D vec);

        Point3D multiplied(Matrix3D m);

        double distanceSquare(Point3D other);

        double distance(Point3D other);

        Point3D middle(Point3D other);

        bool isCoincide(Point3D other);

        bool isIdentical(Point3D other);

        Point3D operator+(Vector3D vec);

        Point3D operator-(Vector3D vec);

        Vector3D operator-(Point3D other);

        Point3D operator*(Matrix3D m);

        bool operator==(const Point3D& p);

        bool operator!=(const Point3D& p);
    };
}