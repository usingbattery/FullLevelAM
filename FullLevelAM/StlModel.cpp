#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include "StlModel.h"

namespace nsp {

	StlModel::StlModel(std::string filepath) {
		readStlFile(filepath);
	}

	void StlModel::readStlFile(std::string filePath) {

		//prepare file
		File stlFile(filePath);
		std::string text;
		bool hasLeft = true;

		//prepare triangle
		Triangle triangle;
		double x = 0, y = 0, z = 0;
		Point3D P[3];
		int pIndex = 0;
		Vector3D N;

		//start read
		while (hasLeft) {
			hasLeft = stlFile.read(&text);
			if (text == "normal") {
				readXYZ(&stlFile, &x, &y, &z);
				N = Vector3D(x, y, z);
				pIndex = 0;
			}
			else if (text == "vertex") {
				readXYZ(&stlFile, &x, &y, &z);
				P[pIndex] = Point3D(x, y, z);
				pIndex++;
			}
			else if (text == "endfacet") {
				triangle = Triangle(P[0], P[1], P[2], N);
				triangles.push_back(triangle);
				updateBound(P);
			}
		}
	}

	void StlModel::readXYZ(File* stlFile, double* x, double* y, double* z) {
		std::string text;
		(*stlFile).read(&text);
		*x = std::stod(text.c_str());
		(*stlFile).read(&text);
		*y = std::stod(text.c_str());
		(*stlFile).read(&text);
		*z = std::stod(text.c_str());
	}

	void StlModel::updateBound(Point3D P[]) {
		bound[0] = std::min({ bound[0], P[0].x, P[1].x, P[2].x });
		bound[1] = std::min({ bound[1], P[0].y, P[1].y, P[2].y });
		bound[2] = std::min({ bound[2], P[0].z, P[1].z, P[2].z });
		bound[3] = std::max({ bound[3], P[0].x, P[1].x, P[2].x });
		bound[4] = std::max({ bound[4], P[0].y, P[1].y, P[2].y });
		bound[5] = std::max({ bound[5], P[0].z, P[1].z, P[2].z });
	}

	int StlModel::getFacetNumber() {
		return triangles.size();
	}
}