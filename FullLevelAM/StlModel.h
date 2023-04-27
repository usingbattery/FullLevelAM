//
// Created by MBP on 2023/4/18.
//

#ifndef GCODE_STLMODEL_H
#define GCODE_STLMODEL_H

#include "Triangle.h"
#include "File.h"
namespace nsp {

    class StlModel {
    public:
        StlModel();

        StlModel(std::vector<Triangle> trs = std::vector<Triangle>());

        //获取STL模型中的面片数
        int getFacetNumber();

        //从文本中提取坐标，被readStlFile调用
        std::vector<double> getCoords(std::string line);

        //读取STL文件，输入文件路径
        void readStlFile(std::string filepath);

        //从vtkSTLReader提取面片信息
        void extractFromVtkStlReader();

        //获取模型6个方向边界值极值
        std::vector<double> getBound();

        std::vector<Triangle> triangles;
        std::vector<double> bound;
        double xMin = 0;
        double yMin = 0;
        double zMin = 0;
        double xMax = 0;
        double yMax = 0;
        double zMax = 0;
    private:

    };

}
#endif //GCODE_STLMODEL_H
