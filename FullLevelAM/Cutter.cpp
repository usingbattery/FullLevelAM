#include "Cutter.h"
#include "fun.h"
#include<algorithm>

namespace nsp {

	Cutter::Cutter(StlModel stlModel, double* heights, int heightNum, bool isSorted) {
		if (!isSorted) {
			std::sort(heights, heights + heightNum);
		}
		init(heights, heightNum);
		/*for (int i = 0; i < layersNum; i++) {
			std::cout << layers[i].plane.toString() << std::endl;
		}*/
		Cut(stlModel.triangles);
	}

	void Cutter::init(double* heights, int heightNum) {
		layersNum = heightNum;
		layers = new Layer[layersNum];
		for (int i = 0; i < layersNum; i++) {
			layers[i].setPlane(Plane(Point3D(0, 0, heights[i]), Vector3D(0, 0, 1)));
		}
	}

	void Cutter::Cut(std::multimap <double, Triangle> triangles) {
		std::multimap <double, Triangle>::iterator it = triangles.begin();
		std::vector<Triangle> trianglesTem;
		for (int i = 0; i < layersNum; i++) {
			trianglesTem = layers[i].intersectStlLayer(trianglesTem, &triangles, &it);
			//std::cout << it->second.toString() << std::endl;
			/*for (Triangle t : trianglesTem) {
				std::cout << t.A.toString() << std::endl;
			}*/
		}
	}
}