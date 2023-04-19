#pragma once
#include"Point3D.h"
class Segment {

public:
	Point3D A;
	Point3D B;
	Segment(Point3D a = Point3D(), Point3D b = Point3D());

	void length();


	void direction();


	void swap();


};
