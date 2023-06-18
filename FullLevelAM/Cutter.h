#pragma once

#include "Layer.h"
#include "CutTriangle.h"

namespace nsp {

	class Cutter {

	public:

		Cutter(StlModel stlModel, double distance = 1.0);
		Cutter(StlModel stlModel, int layersNum);
		Cutter(StlModel stlModel, std::vector<double> heights, bool isSorted = false);

		std::vector<Layer> layers;

	private:

		std::vector <CutTriangle> trianglesZmin;
		std::vector <CutTriangle> trianglesZmax;

		std::vector<double> creatHeights(double zMin, double zMax, int layersNum, double distance);

		void initLayers(std::vector<double>heights);

		void initTriangles(std::vector<Triangle>* triangles);

		void cut();

		void link();
	};
}