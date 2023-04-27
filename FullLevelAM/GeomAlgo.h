//
// Created by MBP on 2023/4/18.
//

#ifndef FULLLEVELAM_GEOMALGO_H
#define FULLLEVELAM_GEOMALGO_H

#include "Point3D.h"
#include "Line.h"
#include "Segment.h"
#include "Plane.h"
#include "Ray.h"
#include "Polyline.h"
#include<tuple>

namespace nsp {

	bool nearZero(double x);

	double distance(Point3D obj1, Line obj2);

	double distance(Point3D obj1, Ray obj2);

	double distance(Point3D obj1, Segment obj2);

	double distance(Point3D obj1, Plane obj2);

	double distance(Line obj1, Line obj2);

	double distance(Line obj1, Plane obj2);

	double distance(Ray obj1, Plane obj2);

	double distance(Segment obj1, Plane obj2);

	//直线与直线相交，返回交点。因为是多返回值，所以采用tuple<>的结构返回，调用此函数时，请注意返回值的格式
	//bool类型用于判断是否有交点，当返回的tuple里bool为false时，说明无交点，为true时，返回的p即为交点
	std::tuple<Point3D, double, double, bool> intersectLineLine(Line, Line);

	//计算线段和平面的交点并返回
	std::tuple<Point3D, bool>  intersectSegmentPlane(Segment seg, Plane plane);

	//实体求交计算
	std::tuple<Point3D, bool>  intersect(Line, Line);
	std::tuple<Point3D, bool>  intersect(Segment, Segment);
	std::tuple<Point3D, bool>  intersect(Line, Segment);
	std::tuple<Point3D, bool>  intersect(Line, Plane);
	std::tuple<Point3D, bool>  intersect(Segment, Plane);


	bool pointOnRay(Point3D p, Ray ray);

	int pointInPolygon(Point3D p, Polyline polygon);


}


#endif //FULLLEVELAM_GEOMALGO_H
