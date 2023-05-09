#pragma once

#include <map>
#include "Triangle.h"
#include "File.h"

namespace nsp {

	class StlModel {

	public:

		double bound[6];

		std::multimap <double, Triangle> triangles;

		StlModel(std::string filepath = "0.STL");

		//Obtain the number of patches in the STL model
		int getFacetNumber();

	private:

		//Read the STL file 
		void readStlFile(std::string filepath);

		void readXYZ(File* stlFile, double* x, double* y, double* z);

		void updateBound(Point3D P[]);
	};
}