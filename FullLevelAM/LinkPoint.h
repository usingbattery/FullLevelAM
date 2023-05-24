#pragma once
#include "Point3D.h"
namespace nsp {
	class LinkPoint
	{
	public:
		LinkPoint(Point3D pnt3d = Point3D(), unsigned int digits = 7);
		double x;
		double y;
		double z;
		LinkPoint* other = nullptr;
		bool used = false;
		int index = 0;
		Point3D toPoint3D() {
			return Point3D(x, y, z);
		}
		double round(double d, unsigned int digits = 7);

		bool operator==(LinkPoint lp);
	};
}
