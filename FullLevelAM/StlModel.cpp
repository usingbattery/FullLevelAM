//
// Created by MBP on 2023/4/18.
//

#include "StlModel.h"
#include <algorithm>
namespace nsp {

	StlModel::StlModel(std::string filepath) {
		readStlFile(filepath);
		initFacetNumber();
	}

	void StlModel::readStlFile(std::string filepath) {

		//prepare file
		File stlFile = File(filepath);
		std::string text;
		bool hasLeft = true;

		//prepare triangle
		Triangle triangle;
		double dx = 0, dy = 0, dz = 0;
		Point3D A, B, C;
		Vector3D N;

		//start read
		while (hasLeft) {
			text = "";
			hasLeft = stlFile.read(&text);
			if (line.substr(0, 12) == "facet normal") {
				std::vector<double> vec_tmp = getCoords(line);
				dx = vec_tmp[0];
				dy = vec_tmp[1];
				dz = vec_tmp[2];
				N = Vector3D(dx, dy, dz);
				std::getline(f.infile, line);
				A.x = getCoords(line)[0];
				A.y = getCoords(line)[1];
				A.z = getCoords(line)[2];

				std::getline(f.infile, line);
				B.x = getCoords(line)[0];
				B.y = getCoords(line)[1];
				B.z = getCoords(line)[2];

				std::getline(f.infile, line);
				C.x = getCoords(line)[0];
				C.y = getCoords(line)[1];
				C.z = getCoords(line)[2];
				triangles.push_back(Triangle(A, B, C, N));
			}
			refreshBound(bound, triangle);
		}
	}

	void StlModel::initFacetNumber() {
		facetNumber = triangles.size();
	}

	void refreshBound(double* bound, Triangle t) {
		bound[0] = std::min({ bound[0], t.A.x, t.B.x, t.C.x });
		bound[1] = std::min({ bound[1], t.A.y, t.B.y, t.C.y });
		bound[2] = std::min({ bound[2], t.A.z, t.B.z, t.C.z });
		bound[3] = std::max({ bound[3], t.A.x, t.B.x, t.C.x });
		bound[4] = std::max({ bound[4], t.A.y, t.B.y, t.C.y });
		bound[5] = std::max({ bound[5], t.A.z, t.B.z, t.C.z });
	}
}