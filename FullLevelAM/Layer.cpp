#include "Layer.h"
#include "Fun.h"

namespace nsp {

	void Layer::moveUp(Layer* preLayer, std::vector <SortedTriangle>* trianglesZmin, double height) {
		this->plane.P.z += height;
		std::vector<Segment> segmentsTem;
		int border = -1;
		for (SortedTriangle* preTriangle : preLayer->triangles) {
			segmentsTem = intersectTrianglePlane(*(preTriangle->triangle), this->plane);
			record(&segmentsTem, preTriangle);
			if (preTriangle->iMin > border) {
				border = preTriangle->iMin;
			}
		}
		for (int i = border + 1; i < (*trianglesZmin).size(); i++) {
			if ((*trianglesZmin)[i].triangle->zMinPnt() > this->plane.P.z) {
				break;
			}
			segmentsTem = intersectTrianglePlane(*((*trianglesZmin)[i].triangle), this->plane);
			record(&segmentsTem, &((*trianglesZmin)[i]));
		}
	}

	void Layer::moveDown(Layer* preLayer, std::vector <SortedTriangle>* trianglesZmax, double height) {
		this->plane.P.z -= height;
		std::vector<Segment> segmentsTem;
		int border = -1;
		for (SortedTriangle* preTriangle : preLayer->triangles) {
			segmentsTem = intersectTrianglePlane(*(preTriangle->triangle), this->plane);
			record(&segmentsTem, preTriangle);
			if (preTriangle->jMax > border) {
				border = preTriangle->jMax;
			}
		}
		for (int i = border + 1; i < (*trianglesZmax).size(); i++) {
			if ((*trianglesZmax)[i].triangle->zMaxPnt() < this->plane.P.z) {
				break;
			}
			segmentsTem = intersectTrianglePlane(*((*trianglesZmax)[i].triangle), this->plane);
			record(&segmentsTem, &((*trianglesZmax)[i]));
		}
	}

	void Layer::record(std::vector<Segment>* segmentsTem, SortedTriangle* triangleTem) {
		if ((*segmentsTem).size() > 0) {
			for (int i = 0; i < (*segmentsTem).size(); i++) {
				segments.push_back((*segmentsTem)[i]);
			}
			this->triangles.push_back(triangleTem);
		}
	}
}