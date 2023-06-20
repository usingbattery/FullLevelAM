#pragma once

#include "Layer.h"

namespace nsp {

	class Cutter {

	public:

		Cutter(StlModel* stlModel, std::vector<double> heights);

		std::vector<Layer> layers;

	private:

		std::vector <SortedTriangle> trianglesZmin;
		std::vector <SortedTriangle> trianglesZmax;
		std::vector<Layer*> sortedLayers;

		void sortTriangles(std::vector<Triangle>* triangles);

		void initLayers(std::vector<double>heights);

		void sortLayers();

		void cut();
	};
}