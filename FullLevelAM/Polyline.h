//
// Created by MBP on 2023/4/18.
//

#ifndef GCODE_POLYLINE_H
#define GCODE_POLYLINE_H

#include "Segment.h"
namespace nsp {

    class Polyline {
    public:


        std::vector<Point3D> points;

        Polyline() {
        }

        //克隆一条多线段
        Polyline clone();

        //获取多线段中点的数量
        int count();

        //在多线段末尾添加一个点
        void addPoint(Point3D pt);

        //在多线段起点前增加一个点
        void raddPoint(Point3D pt);

        //根据点的序号移除一个点
        void removePoint(int index);

        //根据点的序号获取一个点
        Point3D point(int index);

        //获取起点
        Point3D startPoint();

        //获取终点
        Point3D endPoint();

        //判断多线段是否闭合
        bool isClosed();

        //对多段线的点序进行反向操作
        void reverse();

        //获取多边形面积
        double getArea();

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

}
#endif //GCODE_POLYLINE_H
