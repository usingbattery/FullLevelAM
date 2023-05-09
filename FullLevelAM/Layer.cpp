#include "Layer.h"

namespace nsp {

	void Layer::setPlane(Plane plane_) {
		this->plane = plane_;
	}

	std::vector<Triangle> Layer::intersectStlLayer(std::vector<Triangle> preTriangles, std::multimap <double, Triangle> restTriangles, std::multimap <double, Triangle>::iterator it) {
		std::vector<Triangle> curTriangles;
		return curTriangles;
	}

	void Layer::intersectTriangleLayer(std::vector<Triangle> preTriangles) {
		/*bool cross = true;
		while (cross) {
		}*/
	}
}