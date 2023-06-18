#include "Cutter.h"
#include "fun.h"
#include<algorithm>
#include"LinkSegs_dlook.h"

namespace nsp {

	Cutter::Cutter(StlModel stlModel, double distance) {
		init(stlModel.bound[2], stlModel.bound[5], distance);
		Cut(stlModel.triangles);
	}

	Cutter::Cutter(StlModel stlModel, int layersNum) {
		double distance = ((stlModel.bound[5] - stlModel.bound[2]) / layersNum);
		init(stlModel.bound[2], stlModel.bound[5], distance);
		Cut(stlModel.triangles);
	}

	Cutter::Cutter(StlModel stlModel, double* heights, int heightNum, bool isSorted) {
		if (!isSorted) {
			std::sort(heights, heights + heightNum);
		}
		init(heights, heightNum);
		/*for (int i = 0; i < layersNum; i++) {
			std::cout << layers[i].plane.toString() << std::endl;
		}*/
		Cut(stlModel.triangles);
		/*for (int i = 0; i < layersNum; i++) {
			LinkSegs_dlook link = LinkSegs_dlook(layers[i].segments);
			link.Link();
			layers[i].segments = link.segs;
		}*/
	}

	void Cutter::init(double zMin, double zMax, double distance) {
		layersNum = 0;
		for (double height = zMin; height < zMax; height+= distance) {
			layers[layersNum].setPlane(Plane(Point3D(0, 0, height), Vector3D(0, 0, 1)));
			layersNum++;
		}
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
			//push segment into layer.segments, and return trianglesTem;
			trianglesTem = layers[i].intersectStlLayer(trianglesTem, &triangles, &it);
			//std::cout << it->second.toString() << std::endl;
			/*for (Triangle t : trianglesTem) {
				std::cout << t.A.toString() << std::endl;
			}*/
		}
	}
}