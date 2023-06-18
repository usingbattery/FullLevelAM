#include "Layer.h"
#include "Fun.h"

namespace nsp {

	void Layer::moveUp(Layer* preLayer, std::vector <CutTriangle>* trianglesZmin, double height) {
		this->plane.P.z += height;
		std::vector<Segment> segmentsTem;
		int border = -1;
		double highest = DBL_MIN;
		for (CutTriangle* preTriangle : preLayer->triangles) {
			segmentsTem = intersectTrianglePlane(*(preTriangle->triangle), this->plane);
			if (segmentsTem.size() > 0) {
				for (const Segment& segment : segmentsTem) {
					segments.push_back(segment);
				}
				this->triangles.push_back(preTriangle);
			}
			else {
				continue;
			}
			if (preTriangle->z > highest) {
				highest = preTriangle->z;
				border = preTriangle->index;
			}
		}
		for (int i = border + 1; i < (*trianglesZmin).size(); i++) {
			if ((*trianglesZmin)[i].z > this->plane.P.z) {
				break;
			}
			segmentsTem = intersectTrianglePlane(*((*trianglesZmin)[i].triangle), this->plane);
			if (segmentsTem.size() > 0) {
				for (const Segment& segment : segmentsTem) {
					segments.push_back(segment);
				}
				this->triangles.push_back(&((*trianglesZmin)[i]));
			}
		}
	}

	void Layer::moveDown(Layer* preLayer, std::vector <CutTriangle>* trianglesZmax, double height) {
		this->plane.P.z -= height;
		std::vector<Segment> segmentsTem;
		int border = (*trianglesZmax).size();
		double lowest = DBL_MAX;
		for (CutTriangle* preTriangle : preLayer->triangles) {
			segmentsTem = intersectTrianglePlane(*(preTriangle->triangle), this->plane);
			if (segmentsTem.size() > 0) {
				for (const Segment& segment : segmentsTem) {
					segments.push_back(segment);
				}
				this->triangles.push_back(preTriangle);
			}
			else {
				continue;
			}
			if (preTriangle->z < lowest) {
				lowest = preTriangle->z;
				border = preTriangle->index;
			}
		}
		for (int i = border + 1; i < (*trianglesZmax).size(); i++) {
			if ((*trianglesZmax)[i].z < this->plane.P.z) {
				break;
			}
			segmentsTem = intersectTrianglePlane(*((*trianglesZmax)[i].triangle), this->plane);
			if (segmentsTem.size() > 0) {
				for (const Segment& segment : segmentsTem) {
					segments.push_back(segment);
				}
				this->triangles.push_back(&((*trianglesZmax)[i]));
			}
		}
	}
}