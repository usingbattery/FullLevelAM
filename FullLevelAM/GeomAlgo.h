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

//几何算法模块

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

	//The line intersects with the line and returns the intersection point.
	//Because it returns multiple values, a tuple<>structure is used to return. When calling this function, please pay attention to the format of the return value
	
	//The bool type is used to determine whether there are intersections
	//When bool in the returned tuple is false, it indicates that there is no intersection point. When it is true, the returned p is the intersection point
	std::tuple<Point3D, double, double, bool> intersectLineLine(Line, Line);

	//Calculate the intersection point of a line segment and a plane and return
	std::vector<std::shared_ptr<Point3D>>  intersectSegmentPlane(Segment seg, Plane plane);

	//Solid Intersection Calculation
	std::tuple<Point3D, bool>  intersect(Line, Line);
	std::tuple<Point3D, bool>  intersect(Segment, Segment);
	std::tuple<Point3D, bool>  intersect(Line, Segment);
	std::tuple<Point3D, bool>  intersect(Line, Plane);
	std::shared_ptr<Point3D>  intersect(Segment, Plane);


	bool pointOnRay(Point3D p, Ray ray);

	int pointInPolygon(Point3D p, Polyline polygon);


}


#endif //FULLLEVELAM_GEOMALGO_H
