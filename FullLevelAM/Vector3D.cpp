#define _USE_MATH_DEFINES

#include <iostream>
#include <sstream>
#include <iomanip>
#include<math.h>
#include "Vector3D.h"
namespace nsp {

    Vector3D::Vector3D(double dx, double dy, double dz, double dw) {
        this->dx = dx;
        this->dy = dy;
        this->dz = dz;
        this->dw = dw;
    }

    std::string Vector3D::toString() {
        std::string res = "Vector3D:";
        std::stringstream stringTem;
        int precision = 1;
        stringTem << std::setiosflags(std::ios::fixed) << std::setprecision(precision) << dx;
        res += stringTem.str() + ",";
        stringTem.str("");
        stringTem << std::setiosflags(std::ios::fixed) << std::setprecision(precision) << dy;
        res += stringTem.str() + ",";
        stringTem.str("");
        stringTem << std::setiosflags(std::ios::fixed) << std::setprecision(precision) << dz;
        res += stringTem.str();
        return res;
    }

    Vector3D Vector3D::clone() {
        return Vector3D(this->dx, this->dy, this->dz, this->dw);
    }

    void Vector3D::reverse() {
        this->dx = -this->dx;
        this->dy = -this->dy;
        this->dz = -this->dz;
    }

    Vector3D Vector3D::reversed() {
        return Vector3D(-this->dx, -this->dy, -this->dz);
    }

    double Vector3D::dotProduct(Vector3D vec) {
        return this->dx * vec.dx + this->dy * vec.dy + this->dz * vec.dz;
    }

    Vector3D Vector3D::crossProduct(Vector3D vec) {
        return Vector3D(
                this->dy * vec.dz - this->dz * vec.dy,
                this->dz * vec.dx - this->dx * vec.dz,
                this->dx * vec.dy - this->dy * vec.dx);
    }

    void Vector3D::amplify(double f) {
        this->dx = f * this->dx;
        this->dy = f * this->dy;
        this->dz = f * this->dz;
    }

    Vector3D Vector3D::amplified(double f) {
        return Vector3D(f * this->dx, f * this->dy, f * this->dz);
    }

    double Vector3D::lengthSquare() {
        return pow(this->dx, 2) + pow(this->dy, 2) + pow(this->dz, 2) + pow(this->dw, 2);
    }

    double Vector3D::length() {
        return sqrt(this->lengthSquare());
    }

    void Vector3D::normalize() {
        double len = this->length();
        this->dx = this->dx / len;
        this->dy = this->dy / len;
        this->dz = this->dz / len;
    }

    Vector3D Vector3D::normalized() {
        double len = this->length();
        return Vector3D(
                this->dx = this->dx / len,
                this->dy = this->dy / len,
                this->dz = this->dz / len);
    }

    bool Vector3D::isZeroVector() {
        return this->lengthSquare() == 0.0;
    }

    Vector3D Vector3D::multiplied(Matrix3D m) {
        return Vector3D(
                this->dx * m.a[0][0] + this->dy * m.a[1][0] + this->dz * m.a[2][0] + this->dw * m.a[3][0],
                this->dx * m.a[0][1] + this->dy * m.a[1][1] + this->dz * m.a[2][1] + this->dw * m.a[3][1],
                this->dx * m.a[0][2] + this->dy * m.a[1][2] + this->dz * m.a[2][2] + this->dw * m.a[3][2]);
    }

    bool Vector3D::isParallel(Vector3D other) {
        return this->crossProduct(other).isZeroVector();
    }

    double Vector3D::getAngle(Vector3D vec) {
        Vector3D v1 = this->normalized();
        Vector3D v2 = vec.normalized();
        double dotPro = v1.dotProduct(v2);
        if (dotPro > 1) {
            dotPro = 1;
        } else if (dotPro < -1) {
            dotPro = -1;
        }
        return acos(dotPro);
    }

    Vector3D Vector3D::getOrthoVector2D() {
        if (this->dx == 0) {
            return Vector3D(1, 0, 0).normalized();
        } else {
            return Vector3D(this->dy / this->dx, 1, 0).normalized();
        }
    }

    double Vector3D::getAngle2D(Vector3D vec) {
        double rad = this->getAngle(Vector3D(1, 0, 0));
        if (this->dy < 0) {
            rad = 2 * M_PI - rad;
        }
        return rad;
    }

    Vector3D Vector3D::operator+(Vector3D other) {
        return Vector3D(this->dx + other.dx, this->dy + other.dy, this->dz + other.dz);
    }

    Vector3D Vector3D::operator-(Vector3D other) {
        return this->clone() + other.reversed();
    }

    Vector3D Vector3D::operator*(Matrix3D m) {
        return this->multiplied(m);
    }

    bool Vector3D::operator==(Vector3D vector3D) {
        return dx == vector3D.dx && dy == vector3D.dy && dz == vector3D.dz;
    }

    bool Vector3D::operator!=(Vector3D vector3D) {
        return !this->operator==(vector3D);
    }

}