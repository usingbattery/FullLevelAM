#include "LinkPoint.h"
namespace nsp {
	LinkPoint::LinkPoint(Point3D pnt3d, unsigned int digits) {
		x = round(pnt3d.x, digits);
		y = round(pnt3d.y, digits);
		z = round(pnt3d.z, digits);
		
	}
	double LinkPoint::round(double d, unsigned int digits) {
		int i = d;
		double tmp_d = d - i;
		int res = ((int)(tmp_d * pow(10, digits + 1)) % 10) >= 5 ? 1 : 0;

		return i + ((double)(int)(tmp_d * pow(10, digits) + res)) / (pow(10, digits));
	}

	bool LinkPoint::operator==(LinkPoint lp) {

		if (this->x == lp.x && this->y == lp.y && this->z == lp.z) {
			return true;
		}
		return false;
	}
}