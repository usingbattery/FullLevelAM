//
// Created by MBP on 2023/4/18.
//

#ifndef GCODE_POLYLINE_H
#define GCODE_POLYLINE_H

#include "nsp.h"
class Polyline {
public:
    //将XY平面上的多边形调整成逆时针方向
    void makeCCW();
    //将XY平面上的多边形调整成顺时针方向
    void makeCW();
    //判断多边形是否为逆时针方向
    bool isCCW();
    //根据一个向量平移多线段
    void translate(Vector3D vec);
    //在多线段的开头或结尾添加一条线段
    bool appendSegment(Segment seg);


private:

};


#endif //GCODE_POLYLINE_H
