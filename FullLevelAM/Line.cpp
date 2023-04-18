#include"Line.h"

line::line(Point3D p, Vector3D v) {
	this->p = p.clone();
	this->v = v.clone().normalized();
}