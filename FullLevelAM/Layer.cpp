#include "Layer.h"
#include "GeomAlgo.h"

namespace nsp {

	void Layer::moveUp(Layer* preLayer, std::vector <SortedTriangle>* trianglesZmin, double height) {
		std::vector<SortedTriangle*> preTriangles= preLayer->triangles;
		reInit(height);
		std::vector<Segment> segmentsTem;
		int border = -1;
		for (SortedTriangle* preTriangle : preTriangles) {
			segmentsTem = intersect(*(preTriangle->triangle), this->plane);
			record(&segmentsTem, preTriangle);
			if (preTriangle->iMin > border) {
				border = preTriangle->iMin;
			}
		}
		for (int i = border + 1; i < (*trianglesZmin).size(); i++) {
			if ((*trianglesZmin)[i].triangle->zMinPnt() > this->plane.P.z) {
				break;
			}
			segmentsTem = intersect(*((*trianglesZmin)[i].triangle), this->plane);
			record(&segmentsTem, &((*trianglesZmin)[i]));
		}
	}

	void Layer::moveDown(Layer* preLayer, std::vector <SortedTriangle>* trianglesZmax, double height) {
		std::vector<SortedTriangle*> preTriangles = preLayer->triangles;
		reInit(height);
		std::vector<Segment> segmentsTem;
		int border = -1;
		for (SortedTriangle* preTriangle : preTriangles) {
			segmentsTem = intersect(*(preTriangle->triangle), this->plane);
			record(&segmentsTem, preTriangle);
			if (preTriangle->jMax > border) {
				border = preTriangle->jMax;
			}
		}
		for (int i = border + 1; i < (*trianglesZmax).size(); i++) {
			if ((*trianglesZmax)[i].triangle->zMaxPnt() < this->plane.P.z) {
				break;
			}
			segmentsTem = intersect(*((*trianglesZmax)[i].triangle), this->plane);
			record(&segmentsTem, &((*trianglesZmax)[i]));
		}
	}

	Layer Layer::clone() {
		Layer clone;
		clone.triangles = std::vector<SortedTriangle*>(this->triangles);
		return clone;
	}

	void Layer::reInit(double height) {
		this->plane.P.z=height;
		this->triangles.clear();
		this->segments.clear();
		this->contours.clear();
	}

	void Layer::record(std::vector<Segment>* segmentsTem, SortedTriangle* triangleTem) {
		if ((*segmentsTem).size() > 0) {
			for (int i = 0; i < (*segmentsTem).size(); i++) {
				segments.push_back((*segmentsTem)[i]);
			}
			this->triangles.push_back(triangleTem);
		}
	}

	void Layer::link() {
		this->contours = linkSegs(this->segments);
	}
}