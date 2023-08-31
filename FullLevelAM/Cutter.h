#pragma once

#include "Layer.h"

namespace nsp {

	class Cutter {

	public:

		std::vector<Layer> layers;

		std::vector<SortedTriangle> zMinLowToHigh;
		std::vector<SortedTriangle> zMaxHighToLow;

		Cutter(StlModel* stlModel, std::vector<double> heights);

		int curLayerIndex;
		void forward();

	private:

		std::multimap<double, Layer*> sortedLayers;

		void sortTriangles(std::vector<Triangle>* triangles);

		void initLayers(std::vector<double> heights);

		void sortLayers(std::vector<double> heights);

		void cut();

		void link();
	};
}