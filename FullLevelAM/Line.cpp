#include"Line.h"
namespace nsp {
    Line::Line(Point3D p, Vector3D v) {
        this->p = p.clone();
        this->v = v.clone().normalized();
    }

    std::string Line::toString() {
        std::string res = "Line:";
        return res+p.toString()+v.toString();
    }

    bool Line::operator==(Line line) {
        return p == line.p && v == line.v;
    }

    bool Line::operator!=(Line line) {
        return !this->operator==(line);
    }
}