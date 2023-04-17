#ifndef POINT3D
#define POINT3D

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Vector3D.h"
#include "Matrix3D.h"

using namespace vector3d;
using namespace matrix3d;

const double epsilon = 1.4916681462400413e-154;// min value
const double epsilonSquare = DBL_MIN;// min value^2 = 2.2250738585072014e-308

namespace point3d {

	class Point3D {

	public:

		double x;
		double y;
		double z;
		double w;

		Point3D(double x = 0, double  y = 0, double  z = 0, double  w = 1) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		std::string toString() {
			std::string res = "Point3D:";
			std::stringstream stringTem;
			int precision = 1;
			stringTem << std::setiosflags(std::ios::fixed) << std::setprecision(1) << x;
			res += stringTem.str() + ",";
			stringTem.str("");
			stringTem << std::setiosflags(std::ios::fixed) << std::setprecision(precision) << y;
			res += stringTem.str() + ",";
			stringTem.str("");
			stringTem << std::setiosflags(std::ios::fixed) << std::setprecision(precision) << z;
			res += stringTem.str();
			return res;
		}

		Point3D clone() {
			return Point3D(this->x, this->y, this->z, this->w);
		}

		Vector3D pointTo(Point3D other) {
			return Vector3D(other.x - this->x, other.y - this->y, other.z - this->z);
		}

		void translate(Vector3D vec) {
			this->x += vec.w;
			this->y += vec.y;
			this->z += vec.z;
		}

		Point3D translated(Vector3D vec) {
			this->translate(vec);
			return this->clone();
		}

		Point3D multiplied(Matrix3D m) {
			return Point3D(
				this->x * m.a[0][0] + this->y * m.a[1][0] + this->z * m.a[2][0] + this->w * m.a[3][0],
				this->x * m.a[0][1] + this->y * m.a[1][1] + this->z * m.a[2][1] + this->w * m.a[3][1],
				this->x * m.a[0][2] + this->y * m.a[1][2] + this->z * m.a[2][2] + this->w * m.a[3][2]);
		}

		double distanceSquare(Point3D other) {
			return this->pointTo(other).lengthSquare();
		}

		double distance(Point3D other) {
			return this->pointTo(other).length();
		}

		Point3D middle(Point3D other) {
			return Point3D((other.x + this->x) / 2, (other.y + this->y) / 2, (other.z + this->z) / 2);
		}

		bool isCoincide(Point3D other, double dis2 = epsilonSquare) {
			return this->pointTo(other).lengthSquare() < dis2;
		}

		bool isIdentical(Point3D other) {
			return other.x == this->x && other.y == this->y && other.z == this->z;
		}

		Point3D operator+(Vector3D vec) {
			return this->translated(vec);
		}

		Point3D operator-(Vector3D vec) {
			vec.reversed();
			return this->translated(vec);
		}

		Vector3D operator-(Point3D other) {
			return other.pointTo(this->clone());
		}

		Point3D operator*(Matrix3D m) {
			return this->multiplied(m);
		}
	};
}
#endif //POINT3D