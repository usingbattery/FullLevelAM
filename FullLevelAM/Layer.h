#pragma once

#include "Plane.h"
#include "Segment.h"
#include "StlModel.h"
#include "LinkSegs.h"
#include "Circle.h"

namespace nsp {

	struct SortedTriangle {
		Triangle* triangle;
		int iMin;
		int jMax;
	};

	class Layer {

	public:

		//current layer
		Plane plane;
		//intersected segment
		std::vector<Segment> segments;
		//intersected one or several Polyline
		std::vector<Polyline> contours;

		Circle circleOuter;
		Circle circleInner;

		Layer() {};
		Layer(Plane plane=Plane()) :plane(plane) {};

		std::vector<Triangle> intersectStlLayer(std::vector<Triangle> preTriangles, std::multimap <double, Triangle>* triangles, std::multimap <double, Triangle>::iterator* it);

		void link();

	private:

	};
}