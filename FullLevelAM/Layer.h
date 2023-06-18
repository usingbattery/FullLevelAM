#pragma once

#include "Plane.h"
#include "Segment.h"
#include "StlModel.h"
#include "CutTriangle.h"

namespace nsp {

	class Layer {

	public:

		//current layer
		Plane plane;
		//intersected triangles
		std::vector<CutTriangle*> triangles;
		//intersected segment
		std::vector<Segment> segments;
		//intersected segment in order
		std::vector<Segment> contours;

		Layer(Plane plane) :plane(plane) {};

		void moveUp(Layer* preLayer, std::vector <CutTriangle>* trianglesZmin, double height = 0);

		void moveDown(Layer* preLayer, std::vector <CutTriangle>* trianglesZmax, double height = 0);

	private:

	};
}