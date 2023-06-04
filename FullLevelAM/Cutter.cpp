#include "Cutter.h"
#include "fun.h"

namespace nsp {

	Cutter::Cutter(StlModel stlModel, double layerHeight) {
		initLayers(stlModel.bound[2], stlModel.bound[5], layerHeight);
		/*for (int i = 0; i < layersNum; i++) {
			std::cout << layers[i].plane.toString() << std::endl;
		}*/
		intersectStlLayers(stlModel.triangles);
	}

	void Cutter::initLayers(double zMin, double zMax, double layerLength) {
		layersNum = (int)((zMax - zMin) / layerLength)+1;
		layers = new Layer[layersNum];
		double zTem = zMin;
		for (int i = 0; i < layersNum; i++) {
			layers[i].setPlane(Plane(Point3D(0, 0, zTem), Vector3D(0, 0, 1)));
			zTem += layerLength;
		}
	}

	void Cutter::intersectStlLayers(std::multimap <double, Triangle> triangles) {
		std::multimap <double, Triangle>::iterator it = triangles.begin();
		std::vector<Triangle> trianglesTem;
		for (int i = 0; i < layersNum; i++) {
			trianglesTem = layers[i].intersectStlLayer( trianglesTem, &triangles, &it);
			//std::cout << it->second.toString() << std::endl;
			/*for (Triangle t : trianglesTem) {
				std::cout << t.A.toString() << std::endl;
			}*/
		}
	}
}