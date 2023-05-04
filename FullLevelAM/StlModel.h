//
// Created by MBP on 2023/4/18.
//

#pragma once

#include <map>
#include "Triangle.h"
#include "File.h"

namespace nsp {

	class StlModel {

	public:

		StlModel(std::string filepath = "0.STL");

		std::multimap <double, Triangle> getTriangles();

		//Obtain the number of patches in the STL model
		int getFacetNumber();

		double bound[6];

	private:

		std::multimap <double, Triangle> triangles;

		//Read the STL file and enter the file path
		void readStlFile(std::string filepath);

	};
}