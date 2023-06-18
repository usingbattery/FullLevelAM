#include "Cutter.h"
#include<algorithm>
#include"LinkSegs_dlook.h"

namespace nsp {

	Cutter::Cutter(StlModel stlModel, double distance) {
		int layersNum = (stlModel.bound[5] - stlModel.bound[2]) / distance;
		std::vector<double> heights = creatHeights(stlModel.bound[2], stlModel.bound[5], layersNum, distance);
		this->Cutter::Cutter(stlModel, heights, true);
	}

	Cutter::Cutter(StlModel stlModel, int layersNum) {
		double distance = ((stlModel.bound[5] - stlModel.bound[2]) / layersNum);
		std::vector<double> heights = creatHeights(stlModel.bound[2], stlModel.bound[5], layersNum, distance);
		this->Cutter::Cutter(stlModel, heights, true);
	}

	Cutter::Cutter(StlModel stlModel, std::vector<double> heights, bool isSorted) {
		if (!isSorted) {
			std::cout << "Cutter.cpp£ºÉÐÎ´¿ª·¢ÂÒÐòÊÊÅäÆ÷£¡";
		}
		initLayers(heights);
		//for (Layer layer : layers) {
		//	std::cout << layer.plane.P.z << std::endl;
		//}
		initTriangles(&stlModel.triangles);
		Triangle tem = *(trianglesZmin[0].triangle);
		cut();
		//link();
	}

	std::vector<double> Cutter::creatHeights(double zmin, double zmax, int layersNum, double distance) {
		std::vector<double>heights(layersNum);
		for (double height = zmin; height < zmax; height += distance) {
			heights.push_back(height);
		}
		return heights;
	}

	void Cutter::initLayers(std::vector<double> heights) {
		layers.reserve(heights.size());
		//std::cout << layers.size() << std::endl;
		for (int i = 0; i < heights.size(); i++) {
			layers.push_back(Layer(Plane::zPlane(heights[i])));
		}
	}

	void Cutter::initTriangles(std::vector<Triangle> *triangles) {
		std::multimap<double, Triangle*> trianglesZmin_;
		std::multimap<double, Triangle*> trianglesZmax_;
		for (int i = 0; i < (*triangles) .size(); i++) {
			trianglesZmin_.insert(std::pair<double, Triangle*>{(*triangles)[i].zMinPnt(), & ((*triangles)[i])});
			trianglesZmax_.insert(std::pair<double, Triangle*>{(*triangles)[i].zMaxPnt(), & ((*triangles)[i])});
		}
		trianglesZmin.reserve(trianglesZmin_.size());
		trianglesZmax.reserve(trianglesZmax_.size());
		std::multimap<double, Triangle*>::iterator it0 = trianglesZmin_.begin();
		for (int i = 0; i < trianglesZmin_.size(); i++) {
			trianglesZmin.push_back({ i, it0->first, it0->second });
			it0++;
		}
		std::multimap<double, Triangle*>::iterator it1 = trianglesZmax_.end();
		for (int i = 0; i < trianglesZmax_.size(); i++) {
			it1--;
			trianglesZmax.push_back({ i, it1->first, it1->second });
		}
	}

	void Cutter::cut() {
		layers[0].moveUp(&(layers[0]), &trianglesZmin);
		for (int i = 1; i < layers.size(); i++) {
			layers[i].moveUp(&(layers[i - 1]), &trianglesZmin);
		}
	}

	void Cutter::link() {
		for (int i = 0; i < layers.size(); i++) {
			LinkSegs_dlook link = LinkSegs_dlook(layers[i].segments);
			layers[i].contours = link.segs;
		}
	}

}