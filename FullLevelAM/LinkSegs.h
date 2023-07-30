#pragma once

#include "Point3D.h"
#include "Segment.h"
#include "Ray.h"
#include "Polyline.h"

namespace nsp {

	class LinkPoint
	{
	public:
		LinkPoint(Point3D pnt3d = Point3D()) : self(pnt3d) {}
		Point3D self;
		LinkPoint* other = nullptr;
		bool used = false;
		int index = 0;

		bool operator <(const LinkPoint& linkPoint) const {
			if (this->self.x != linkPoint.self.x) {
				return this->self.x< linkPoint.self.x;
			}
			else {
				return this->self.y < linkPoint.self.y;
			}
		}
		bool operator >(const LinkPoint& linkPoint) const {
			if (this->self.x != linkPoint.self.x) {
				return this->self.x > linkPoint.self.x;
			}
			else {
				return this->self.y > linkPoint.self.y;
			}
		}
	};

	std::vector<Polyline> linkSegs(std::vector<Segment> segments);
}