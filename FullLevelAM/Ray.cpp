#include"Ray.h"

namespace nsp {

    //Initialize Ray
    Ray::Ray(Point3D p, Vector3D v) {
        this->P = p.clone();
        this->V = v.clone().normalized();
    }

    std::string Ray::toString() {
        std::string res = "Ray:";
        return res + P.toString() + V.toString();
    }

    bool Ray::operator==(Ray ray) {
        return P == ray.P && V.isParallel(ray.V);
    }

    bool Ray::operator!=(Ray ray) {
        return ! this->operator==(ray);
    }
}