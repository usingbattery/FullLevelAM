#include "Layer.h"
#include "fun.h"

namespace nsp {

	void Layer::setPlane(Plane plane) {
		this->plane = plane;
	}

	std::vector<Triangle> Layer::intersectStlLayer(std::vector<Triangle> preTriangles, std::multimap <double, Triangle>* triangles, std::multimap <double, Triangle>::iterator* it) {
		std::vector<Triangle> curTriangles;
		std::vector<Segment> segmentsTem;
		for (std::vector<Triangle>::iterator it = preTriangles.begin(); it != preTriangles.end(); it++) {
			segmentsTem = intersectTrianglePlane(*it, plane);
			if (segmentsTem.size()>0) {
				for (Segment segment : segmentsTem) {
					segments.push_back(segment);
				}
				curTriangles.push_back(*it);
			}
			else {
				continue;
			}
		}
		for (; ( * it) != ( * triangles).end(); (*it)++) {
			//<bug>
			//std::cout << plane.P.z << "\t";
			segmentsTem = intersectTrianglePlane(( * it)->second, plane);
			//std::cout << segmentTem.toString() << std::endl;
			//</bug>
			if (segmentsTem.size() > 0) {
				for (Segment segment : segmentsTem) {
					segments.push_back(segment);
				}
				curTriangles.push_back((*it)->second);
			}
			else {
				break;
			}
		}
		return curTriangles;
	}
}