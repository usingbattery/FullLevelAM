#include "Cutter.h"
#include<algorithm>

namespace nsp {

	Cutter::Cutter(StlModel* stlModel, std::vector<double> heights, bool isHeightsSorted) {
		if (stlModel == nullptr) {
			curLayerIndex = 0;
			return;
		}
		if (!isHeightsSorted) {
			sort(heights.begin(), heights.end());
		}
		sortTriangles(&((*stlModel).triangles));
		initLayers(heights);
		initThickness();
		//sortLayers(heights);
		//cut();
	}

	void Cutter::sortTriangles(std::vector<Triangle>* triangles) {
		//sort
		for (int i = 0; i < (*triangles).size(); i++) {
			sortedTriangles.insert(std::pair<double, Triangle>{(*triangles)[i].zMinPnt(), (*triangles)[i]});
		}
	}

	void Cutter::initLayers(std::vector<double> heights) {
		layers.reserve(heights.size());
		for (int i = 0; i < heights.size(); i++) {
			layers.push_back(Layer(Plane::zPlane(heights[i])));
		}
		curLayerIndex = 0;
		//std::cout << layers.size() << std::endl;
	}

	void Cutter::initThickness() {
		thickness.reserve(layers.size() - 1);
		for (int i = 0; i < layers.size() - 1; i++) {
			thickness.push_back(Thickness(&(layers[i+1]), &(layers[i])));
		}
	}

	void Cutter::sortLayers(std::vector<double> heights) {
		for (int i = 0; i < layers.size(); i++) {
			sortedLayers.insert(std::pair<double, Layer*>{heights[i], & layers[i]});
		}
	}

	void Cutter::cut() {
		//std::multimap<double, Layer*>::iterator it = sortedLayers.begin();
		//Layer* preLayer = it->second;//init preLayer as any layer whose triangles.size()==0;
		//for (; it != sortedLayers.end(); it++) {
		//	preLayer = it->second;//step forward
		//}
		//for (int i = 0; i < layers.size(); i++) {
		//	//std::cout << layer.plane.P.z << std::endl;
		//	layers[i].link();
		//}
	}

	bool Cutter::forward() {
		if (curLayerIndex >= layers.size()) {
			return false;
		}
		if (curLayerIndex == 0) {
			it = sortedTriangles.begin();
		}
		preTriangles = layers[curLayerIndex].intersectStlLayer(preTriangles, &sortedTriangles, &it);
		layers[curLayerIndex].link();
		curLayerIndex++;
		return true;
	}

	void Cutter::moveLayerTo(int i, double targhtHeight)
	{
		layers[i].plane.P.z = targhtHeight;
		it = sortedTriangles.begin();
		layers[i].intersectStlLayer({}, &sortedTriangles, &it);
	}

}