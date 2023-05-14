#include "Layer.h"
#include "fun.h"

namespace nsp {

	void Layer::setPlane(Plane plane) {
		this->plane = plane;
	}

	std::vector<Triangle> Layer::intersectStlLayer(std::vector<Triangle> preTriangles, std::multimap <double, Triangle> restTriangles, std::multimap <double, Triangle>::iterator it) {
		std::vector<Triangle> curTriangles;
		Segment segmentTem; 
		for (std::vector<Triangle>::iterator it = preTriangles.begin(); it != preTriangles.end(); it++) {
			segmentTem = intersectTrianglePlane(*it, plane);
			if (!segmentTem.isNull()) {
				segments.push_back(segmentTem);
				curTriangles.push_back(*it);
			}
			else {
				continue;
			}
		}
		for (; it != restTriangles.end(); it++) {
			segmentTem = intersectTrianglePlane(it->second, plane);
			if (!segmentTem.isNull()) {
				segments.push_back(segmentTem);
				curTriangles.push_back(it->second);
			}
			else {
				break;
			}
		}
		return curTriangles;
	}
}