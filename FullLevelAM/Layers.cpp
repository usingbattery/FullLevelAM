#include "Layers.h"
#include "fun.h"

namespace nsp {

	Layers::Layers(StlModel stlModel, double layerHeight) {
		initLayers(stlModel.bound[2], stlModel.bound[5], layerHeight);
		/*for (int i = 0; i < layersNum; i++) {
				std::cout << layers[i].plane.toString() << std::endl;
		}*/
		intersectStlLayers(stlModel.triangles);
	}

	void Layers::initLayers(double zMin, double zMax, double layerLength) {
		layersNum = (int)((zMax - zMin) / layerLength)+1;
		layers = new Layer[layersNum];
		double zTem = zMin;
		for (int i = 0; i < layersNum; i++) {
			layers[i].setPlane(Plane(Point3D(0, 0, zTem), Vector3D(0, 0, 1)));
			zTem += layerLength;
		}
	}

	void Layers::intersectStlLayers(std::multimap <double, Triangle> triangles) {
		std::multimap <double, Triangle>::iterator it = triangles.begin();
		std::vector<Triangle> trianglesTem;
		for (int i = 0; i < layersNum; i++) {
			trianglesTem = layers[i].intersectStlLayer(trianglesTem, &triangles, &it);
			/*for (Triangle t : trianglesTem) {
				std::cout << t.A.toString() << std::endl;
			}*/
		}
	}
}