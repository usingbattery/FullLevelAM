#include "Cutter.h"
#include<algorithm>
#include"LinkSegs_dlook.h"

namespace nsp {

	Cutter::Cutter(StlModel* stlModel, std::vector<double> heights) {
		sortTriangles(&((*stlModel).triangles));
		//Triangle tem = *(trianglesZmin[0].triangle);
		initLayers(heights);
		//for (Layer layer : layers) {
		//	std::cout << layer.plane.P.z << std::endl;
		//}
		sortLayers();
		cut();
	}

	void Cutter::sortTriangles(std::vector<Triangle>* triangles) {
		//sort
		std::multimap<double, Triangle*> sortZmin;
		std::multimap<double, Triangle*> sortZmax;
		for (int i = 0; i < (*triangles).size(); i++) {
			sortZmin.insert(std::pair<double, Triangle*>{(*triangles)[i].zMinPnt(), & ((*triangles)[i])});
			sortZmax.insert(std::pair<double, Triangle*>{(*triangles)[i].zMaxPnt(), & ((*triangles)[i])});
		}
		//record
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
		//std::cout << layers.size() << std::endl;
		for (int i = 0; i < heights.size(); i++) {
			layers.push_back(Layer(Plane::zPlane(heights[i])));
		}
	}

	void Cutter::sortLayers() {
		for (int i = 0; i < layers.size(); i++) {
			sortedLayers.insert(std::pair<double, Layer*>{layers[i].plane.P.z, & layers[i]});
		}
	}

	void Cutter::cut() {
		std::multimap<double, Layer*>::iterator it = sortedLayers.begin();
		Layer* preLayer = it->second;//any layer whose triangles.size()==0;
		for (; it != sortedLayers.end(); it++) {
			(*(it->second)).moveUp(preLayer, &zMinLowToHigh);
			preLayer = it->second;//step by step
		}
	}
}