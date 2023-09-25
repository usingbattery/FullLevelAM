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
		//intersected triangles
		std::vector<SortedTriangle*> triangles;
		//intersected segment
		std::vector<Segment> segments;
		//intersected one or several Polyline
		std::vector<Polyline> contours;

		Circle circleOuter;
		Circle circleInner;

		Layer(Plane plane=Plane()) :plane(plane) {};

		void moveUp(Layer* preLayer, std::vector <SortedTriangle>* trianglesZmin, double height);

		void moveDown(Layer* preLayer, std::vector <SortedTriangle>* trianglesZmax, double height);

		Layer clone();

		void link();

	private:

		void reInit(double height);

		void record(std::vector<Segment>* segmentsTem, SortedTriangle* triangleTem);
	};
}