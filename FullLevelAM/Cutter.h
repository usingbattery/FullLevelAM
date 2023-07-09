#pragma once

#include "Layer.h"

namespace nsp {

	class Cutter {

	public:

		Cutter(StlModel* stlModel, std::vector<double> heights);

		std::vector<Layer> layers;

	private:

		std::vector<SortedTriangle> zMinLowToHigh;
		std::vector<SortedTriangle> zMaxHighToLow;
		std::multimap<double, Layer*> sortedLayers;

		void sortTriangles(std::vector<Triangle>* triangles);

		void initLayers(int layerSize);

		void sortLayers(std::vector<double> heights);

		void cut();
	};
}