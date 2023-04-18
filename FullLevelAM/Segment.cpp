#include"Segment.h"

//初始化
Segment::Segment(Point3D a, Point3D b) {
	this->A = a.clone();
	this->B = b.clone();
}

//计算线段长度
void Segment::length() {
	A.distance(B);
}

//计算线段方向
void Segment::direction() {
	A.pointTo(B);
}


//交换线段两个端点
void Segment::swap() {
	Point3D temp;
	temp = A;
	A = B;
	B = temp;
}