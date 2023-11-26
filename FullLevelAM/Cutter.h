#pragma once

#include "Layer.h"

namespace nsp {

	class Cutter {

	public:

		std::vector<Layer> layers;

		Cutter(StlModel* stlModel = nullptr, std::vector<double> heights = {},bool isHeightsSorted=false);

		bool forward();

		void moveLayerTo(int i, double targhtHeight);

	private:

		// sort all triangles in stlmodel, by triangle.zMin, from min to max
		std::vector<SortedTriangle> zMinLowToHigh;
		// sort all triangles in stlmodel, by triangle.zMax, from max to min
		std::vector<SortedTriangle> zMaxHighToLow;

		// the index of the layer in layers, which forward is about to process
		int curLayerIndex;

		// sort layers by layer.height
		std::multimap<double, Layer*> sortedLayers;

		// get zMinLowToHigh and zMaxHighToLow
		void sortTriangles(std::vector<Triangle>* triangles);

		// init layers by heights
		void initLayers(std::vector<double> heights);

		// get sortedLayers
		void sortLayers(std::vector<double> heights);

		// get all layer.segement and .contours in layers
		void cut();

	};
}