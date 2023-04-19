//
// Created by MBP on 2023/4/18.
//

#include "Polyline.h"

#include"Polyline.h"

//克隆一条多线段
Polyline Polyline::clone() {
    Polyline poly;
    for (Point3D c : points) {
        poly.addPoint(c.clone());
    }
    return poly;
}

//获取多线段中点的数量
int Polyline::count() {
    return points.size();
}

//在多线段末尾添加一个点
void Polyline::addPoint(Point3D pt) {
    points.push_back(pt);
}

//在多线段起点前增加一个点
void Polyline::raddPoint(Point3D pt) {
    points.insert(points.begin(), pt);
}

//根据点的序号移除一个点,序号从0开始
void  Polyline::removePoint(int index) {
    points.erase(points.begin()+index);
}

//根据点的序号获取一个点
Point3D Polyline::point(int index) {
    return points[index];
}

//获取起点
Point3D Polyline::startPoint() {
    return points[0];
}

//获取终点
Point3D Polyline::endPoint() {
    return points[points.size() - 1];
}

//判断多线段是否闭合
bool Polyline::isClosed() {
    if (points.size() <= 2) {
        return false;
    }
    return  startPoint().isCoincide(endPoint());
}

//对多段线的点序进行反向操作
void Polyline::reverse() {
    int sz = count();
    for (int i = 0; i < sz / 2; i++) {
        Point3D temp;
        temp = points[sz - i - 1];
        points[sz - i - 1] = points[i];
        points[i] = temp;
    }

}

void Polyline::makeCCW() {
    if(this->getArea()){
        this->reverse();
    }
}

void Polyline::makeCW() {
    if(this->getArea()){
        this->reverse();
    }
}

bool Polyline::isCCW() {
    if(this->getArea() > 0) return true;
    return false;
}

void Polyline::translate(Vector3D vec) {
    for(int i = 0; i < points.size(); i++){
        points[i].translate(vec);
    }
}

bool Polyline::appendSegment(Segment seg) {
    if(this->count() == 0){
        this->points.push_back(seg.A);
        this->points.push_back(seg.B);
    }
    else{
        if(seg.A.isCoincide(points.back())){
            this->points.push_back(seg.B);
        }
        else if(seg.B.isCoincide(points.back())){
            this->points.push_back(seg.A);
        }
        else if(seg.A.isCoincide(points.front())){
            this->points.push_back(seg.B);
        }
        else if(seg.B.isCoincide(points.front())){
            this->points.push_back(seg.A);
        }
        else{
            return false;
        }
    }
    return true;
}

double Polyline::getArea() {
    double area = 0.0;
    for(int i = 0; i < this->count() - 1; i++){
        area += 0.5 * (points[i].x * points[i+1].y - points[i+1].x * points[i].y);
    }
    return area;
}
