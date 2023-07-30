#pragma once

#include "Layer.h"

namespace nsp {

	class Cutter {

	public:

		Cutter(StlModel* stlModel, std::vector<double> heights);

		std::vector<Layer> layers;

		std::vector<SortedTriangle> zMinLowToHigh;
		std::vector<SortedTriangle> zMaxHighToLow;

	private:

		std::multimap<double, Layer*> sortedLayers;

		void sortTriangles(std::vector<Triangle>* triangles);

		void initLayers(int layerSize);

		void sortLayers(std::vector<double> heights);

		void cut();

		void link();
	};
}