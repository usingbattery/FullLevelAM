#include"Ray.h"
namespace nsp {

//��ʼ��
    Ray::Ray(Point3D p, Vector3D v) {
        this->p = p.clone();
        this->v = v.clone().normalized();
    }

    bool Ray::operator==(Ray ray) {
        return p == ray.p && v.isParallel(ray.v);
    }

    bool Ray::operator!=(Ray ray) {
        return ! this->operator==(ray);
    }
}