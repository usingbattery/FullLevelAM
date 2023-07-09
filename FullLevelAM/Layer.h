#pragma once

#include "Plane.h"
#include "Segment.h"
#include "StlModel.h"

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
		//std::vector<SortedTriangle*> triangles;
		std::vector<int> zMinTriangles;
		std::vector<int> zMaxTriangles;
		//intersected segment
		std::vector<Segment> segments;
		//intersected segment in order
		std::vector<Segment> contours;

		Layer(Plane plane=Plane()) :plane(plane) {};

		void moveUp(Layer* preLayer, std::vector <SortedTriangle>* trianglesZmin, double height);

		void moveDown(Layer* preLayer, std::vector <SortedTriangle>* trianglesZmax, double height);

	private:

		void reInit(double height);

		void record(std::vector<Segment>* segmentsTem, SortedTriangle* triangleTem);
	};
}