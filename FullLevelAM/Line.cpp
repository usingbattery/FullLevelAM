#include"Line.h"
namespace nsp {
    Line::Line(Point3D p, Vector3D v) {
        this->p = p.clone();
        this->v = v.clone().normalized();
    }

    bool Line::operator==(Line line) {
        return p == line.p && v == line.v;
    }

    bool Line::operator!=(Line line) {
        return !this->operator==(line);
    }
}