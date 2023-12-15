#include "Layer.h"
#include "GeomAlgo.h"

namespace nsp {

	std::vector<Triangle> Layer::intersectStlLayer(std::vector<Triangle> preTriangles, std::multimap <double, Triangle>* triangles, std::multimap <double, Triangle>::iterator* it) {
		std::vector<Triangle> curTriangles;
		std::vector<Segment> segmentsTem;
		for (std::vector<Triangle>::iterator it = preTriangles.begin(); it != preTriangles.end(); it++) {
			segmentsTem = intersect(*it, this->plane);
			if (segmentsTem.size() > 0) {
				for (const Segment& segment : segmentsTem) {
					segments.push_back(segment);
				}
				curTriangles.push_back(*it);
			}
			else {
				continue;
			}
		}
		for (; (*it) != (*triangles).end(); (*it)++) {
			if ((*it)->first > this->plane.P.z) {
				break;
			}
			//<bug>
			//std::cout << plane.P.z << "\t";
			segmentsTem = intersect((*it)->second, this->plane);
			//std::cout << segmentTem.toString() << std::endl;
			//</bug>
			if (segmentsTem.size() > 0) {
				for (const Segment& segment : segmentsTem) {
					segments.push_back(segment);
				}
				curTriangles.push_back((*it)->second);
			}
		}
		return curTriangles;
	}

	void Layer::link() {
		std::vector<double> minXs = linkSegs(this->segments, &(this->contours));
		if (minXs.size() == 1) {
			circleOuter = Circle(this->contours[0]);
		}
		else if (minXs.size() > 1) {
			if (minXs[0] < minXs[1]) {
				circleOuter = Circle(this->contours[0]);
				circleInner = Circle(this->contours[1]);
			}
			else {
				circleOuter = Circle(this->contours[1]);
				circleInner = Circle(this->contours[0]);
			}
		}
	}
}