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

		//获取STL模型中的面片数
		int getFacetNumber();

		std::map<double,Triangle> triangles;
		double bound[6];

	private:

		//读取STL文件，输入文件路径
		void readStlFile(std::string filepath);

	};
}