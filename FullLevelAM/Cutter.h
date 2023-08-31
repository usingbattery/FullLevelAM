#pragma once

#include "Layer.h"

namespace nsp {

	class Cutter {

	public:

		std::vector<Layer> layers;


		Cutter(StlModel* stlModel, std::vector<double> heights);

		void forward();

	private:

		std::vector<SortedTriangle> zMinLowToHigh;
		std::vector<SortedTriangle> zMaxHighToLow;

		int curLayerIndex;

		std::multimap<double, Layer*> sortedLayers;

		void sortTriangles(std::vector<Triangle>* triangles);

		void initLayers(std::vector<double> heights);

		void sortLayers(std::vector<double> heights);

		void cut();

		void link();
	};
}