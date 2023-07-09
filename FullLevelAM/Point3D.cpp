#include <iostream>
#include <iomanip>
#include <sstream>
#include "Point3D.h"

namespace nsp {

    Point3D::Point3D(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    std::string Point3D::toString() {
        std::string res = "Point3D:";
        std::stringstream stringTem;
        int precision = 1;
        stringTem << std::setiosflags(std::ios::fixed) << std::setprecision(precision) << x;
        res += stringTem.str() + ",";
        stringTem.str("");
        stringTem << std::setiosflags(std::ios::fixed) << std::setprecision(precision) << y;
        res += stringTem.str() + ",";
        stringTem.str("");
        stringTem << std::setiosflags(std::ios::fixed) << std::setprecision(precision) << z;
        res += stringTem.str();
        return res;
    }

    Point3D Point3D::clone() {
        return Point3D(this->x, this->y, this->z);
    }

    Vector3D Point3D::pointTo(Point3D other) {
        return Vector3D(other.x - this->x, other.y - this->y, other.z - this->z);
    }

    void Point3D::translate(Vector3D vec) {
        this->x += vec.dx;
        this->y += vec.dy;
        this->z += vec.dz;
    }

    Point3D Point3D::translated(Vector3D vec) {
        return Point3D(
            this->x += vec.dx,
            this->y += vec.dy,
            this->z += vec.dz);
    }

    Point3D Point3D::multiplied(Matrix3D m) {
        return Point3D(
            this->x * m.a[0][0] + this->y * m.a[1][0] + this->z * m.a[2][0],
            this->x * m.a[0][1] + this->y * m.a[1][1] + this->z * m.a[2][1],
            this->x * m.a[0][2] + this->y * m.a[1][2] + this->z * m.a[2][2]);
    }

    double Point3D::distanceSquare(Point3D other) {
        return this->pointTo(other).lengthSquare();
    }

    double Point3D::distance(Point3D other) {
        return this->pointTo(other).length();
    }

    Point3D Point3D::middle(Point3D other) {
        return Point3D((other.x + this->x) / 2, (other.y + this->y) / 2, (other.z + this->z) / 2);
    }

    bool Point3D::isCoincide(Point3D other) {
        return this->pointTo(other).lengthSquare() < epsilonSquare;
    }

    bool Point3D::isIdentical(Point3D other) {
        return other.x == this->x && other.y == this->y && other.z == this->z;
    }

    Point3D Point3D::operator+(Vector3D vec) {
        return this->translated(vec);
    }

    Point3D Point3D::operator-(Vector3D vec) {
        vec.reversed();
        return this->translated(vec);
    }

    Vector3D Point3D::operator-(Point3D other) {
        return other.pointTo(this->clone());
    }

    Point3D Point3D::operator*(Matrix3D m) {
        return this->multiplied(m);
    }

    bool Point3D::operator==(const Point3D& p) {
        return this->isIdentical(p);
    }

    bool Point3D::operator!=(const Point3D& p) {
        return !this->operator==(p);
    }

}