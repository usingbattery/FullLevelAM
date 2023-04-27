//
// Created by MBP on 2023/4/18.
//

#ifndef GCODE_FUN_H
#define GCODE_FUN_H
//将多边形保存到文本文件

#include "Polyline.h"
#include "Triangle.h"
#include "Plane.h"
#include "Segment.h"
#include "GeomAlgo.h"
#include "Layer.h"
namespace nsp {
//将多边形保存带文本文件
    void writePolyline(std::string path, Polyline polyline, bool clear_txt = true);

    //从文本文件读取多边形
    Polyline readPolyline(std::string path);
    //空间三角形和平面求交
    Segment intersectTrianglePlane(Triangle triangle, Plane plane);

#endif //GCODE_FUN_H
}