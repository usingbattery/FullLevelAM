#pragma once
#include"Point3D.h"

class Ray {
public:
	Point3D p;
	Vector3D v;
	Ray(Point3D p, Vector3D v) {
		this->p = p.clone();
		this->v = v.clone().normalized();
	}
};
