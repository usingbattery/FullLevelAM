#pragma once

#include "Polyline.h"
#include "Triangle.h"
#include "Plane.h"
#include "Segment.h"
#include "GeomAlgo.h"
#include "Layer.h"
#include "LinkPoint.h"

namespace nsp {

	//Intersection of Space Triangle and Plane
	std::vector<Segment> intersectTrianglePlane(Triangle triangle, Plane plane);

	//Define the comparison function for LinkPoint
	int cmp_pntSmaller(const LinkPoint& lp1, const LinkPoint& lp2);
}