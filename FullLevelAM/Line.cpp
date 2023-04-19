#include"Line.h"

Line::Line(Point3D p, Vector3D v) {
	this->p = p.clone();
	this->v = v.clone().normalized();
}