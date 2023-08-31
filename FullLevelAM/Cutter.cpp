#include "Cutter.h"
#include<algorithm>

namespace nsp {

	Cutter::Cutter(StlModel* stlModel, std::vector<double> heights) {
		sortTriangles(&((*stlModel).triangles));
		initLayers(heights);
		//for (Layer layer : layers) {
		//	std::cout << layer.plane.P.z << std::endl;
		//}
		//sortLayers(heights);
		//cut();
		//link();
	}

	void Cutter::sortTriangles(std::vector<Triangle>* triangles) {
		//sort
		std::multimap<double, Triangle*> sortZmin;
		std::multimap<double, Triangle*> sortZmax;
		for (int i = 0; i < (*triangles).size(); i++) {
			sortZmin.insert(std::pair<double, Triangle*>{(*triangles)[i].zMinPnt(), & ((*triangles)[i])});
			sortZmax.insert(std::pair<double, Triangle*>{(*triangles)[i].zMaxPnt(), & ((*triangles)[i])});
		}
		//list
		std::map<Triangle*, int> iMins;
		std::multimap<double, Triangle*>::iterator it0 = sortZmin.begin();
		for (int i = 0; i < sortZmin.size(); i++) {
			iMins.insert(std::pair<Triangle*, int>{it0->second, i});
			it0++;
		}
		std::map<Triangle*, int> jMaxs;
		std::multimap<double, Triangle*>::iterator it1 = sortZmax.begin();
		for (int j = sortZmax.size() - 1; j >= 0; j--) {
			jMaxs.insert(std::pair<Triangle*, int>{it1->second, j});
			it1++;
		}
		//cat
		zMinLowToHigh.resize(sortZmin.size());
		zMaxHighToLow.resize(sortZmax.size());
		for (std::map<Triangle*, int>::iterator it2 = iMins.begin(); it2 != iMins.end(); it2++) {
			Triangle* triangle = it2->first;
			int iMin = it2->second;
			int jMax = jMaxs[triangle];
			zMinLowToHigh[iMin] = { triangle,iMin,jMax };
			zMaxHighToLow[jMax] = { triangle,iMin,jMax };
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

	void Cutter::sortLayers(std::vector<double> heights) {
		for (int i = 0; i < layers.size(); i++) {
			sortedLayers.insert(std::pair<double, Layer*>{heights[i], & layers[i]});
		}
	}

	void Cutter::cut() {
		std::multimap<double, Layer*>::iterator it = sortedLayers.begin();
		Layer* preLayer = it->second;//init preLayer as any layer whose triangles.size()==0;
		for (; it != sortedLayers.end(); it++) {
			(*(it->second)).moveUp(preLayer, &zMinLowToHigh, it->first);
			preLayer = it->second;//step forward
		}
	}

	void Cutter::link() {
		for (int i = 0; i < layers.size(); i++) {
			//std::cout << layer.plane.P.z << std::endl;
			layers[i].link();
		}
	}

	bool Cutter::forward() {
		if (curLayerIndex >= layers.size()) {
			return false;
		}
		Layer* preLayer = nullptr;
		if (curLayerIndex == 0) {
			preLayer = &(layers[0]);
		}
		else {
			preLayer = &(layers[curLayerIndex - 1]);
		}
		layers[curLayerIndex].moveUp(preLayer, &zMinLowToHigh, layers[curLayerIndex].plane.P.z);
		layers[curLayerIndex].link();
		return true;
	}
}