//
// Created by MBP on 2023/4/18.
//

#pragma once

#include "Triangle.h"
#include "File.h"

namespace nsp {

    class StlModel {

    public:

        StlModel(std::string filepath = "C:\\CLion_txt\\text.txt");

        //读取STL文件，输入文件路径
        void readStlFile(std::string filepath);

        //获取STL模型中的面片数
        void initFacetNumber();

        std::vector<Triangle> triangles;
        double bound[6];
        int facetNumber;

    private:

    };

}