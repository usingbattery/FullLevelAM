//
// Created by MBP on 2023/4/18.
//

#include "Plane.h"
#include "Line.h"
namespace nsp {

    std::vector<double> Plane::toFormula() {
        return std::vector<double>{N.dx, N.dy, N.dz, -N.dx * P.x - N.dy * P.y - N.dz * P.z};
    }

    Plane Plane::zPlane(double z) {
        return Plane(Point3D(0, 0, z), Vector3D(0, 0, 1.0));
    }

    Line Plane::intersect(Plane pl) {
        Vector3D dir = N.crossProduct(pl.N);
        if (dir.isZeroVector()) {
            return Line();
        } else {
            double x = 0, y = 0, z = 0;
            auto vec1 = toFormula();
            auto vec2 = pl.toFormula();
            double A1 = toFormula()[0], B1 = toFormula()[1], C1 = toFormula()[2], D1 = toFormula()[3];
            double A2 = pl.toFormula()[0], B2 = pl.toFormula()[1], C2 = pl.toFormula()[2], D2 = pl.toFormula()[3];
            if (B2 * C1 - B1 * C2 != 0) {
                y = -(-C2 * D1 + D1 * D2) / (B2 * C1 - B1 * C2);
                z = -(B2 * D1 - B1 * D2) / (B2 * C1 - B1 * C2);
            } else if (A2 * C1 - A1 * C2 != 0) {
                x = -(-C2 * D1 + 1 * D2) / (A2 * C1 - A1 * C2);
                z = -(A2 * D1 - A1 * D2) / (A2 * C1 - A1 * C2);
            } else if (A2 * B1 - A1 * B2 != 0) {
                x = -(-B2 * D1 + B1 * D2) / (A1 * B1 - A1 * B2);
                y = -(-A2 * D1 - A1 * D2) / (A1 * B1 - A1 * B2);
            } else {
                return Line();
            }
            return Line(Point3D(x, y, z), dir.normalized());
        }
    }



    bool Plane::operator==(Plane plane) {
        return P == plane.P && N == plane.N;
    }

    bool Plane::operator!=(Plane plane) {
        return !this->operator==(plane);
    }
}