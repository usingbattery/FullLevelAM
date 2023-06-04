//
// Created by MBP on 2023/4/18.
//

#include <cmath>
#include "GeomAlgo.h"
namespace nsp {
    bool nearZero(double x) {
        return abs(x) < epsilon;
    }

    double distance(Point3D obj1, Line obj2) {
        Point3D p = obj2.p;
        Point3D q = obj1;
        Vector3D v = obj2.v;
        double t = p.pointTo(q).dotProduct(v);
        Point3D r = p + v.amplified(t);
        return q.distance(r);
    }

    double distance(Point3D obj1, Ray obj2) {
        Point3D p = obj2.P;
        Point3D q = obj1;
        Vector3D v = obj2.V;
        double t = p.pointTo(q).dotProduct(v);
        if (t >= 0) {
            Point3D r = p + v.amplified(t);
            return q.distance(r);
        }
        return q.distance(p);
    }

    double distance(Point3D obj1, Segment obj2) {
        Point3D q = obj1;
        Point3D p = obj2.A;
        Point3D p1 = obj2.B;
        Vector3D v = obj2.direction().normalized();
        auto l = obj2.length();
        double t = p.pointTo(q).dotProduct(v);
        if (t < 0) {
            return q.distance(p);
        }
        else if (t >= l) {
            return q.distance(p1);
        }
        else {
            Point3D r = p + v.amplified(t);
            return q.distance(r);
        }
    }

    double distance(Point3D obj1, Plane obj2) {
        Point3D p = obj2.P;
        Point3D q = obj1;
        Vector3D n = obj2.N;
        double angle = n.getAngle(p.pointTo(q));
        return p.distance(q) * cos(angle);
    }

    double distance(Line obj1, Line obj2) {
        Point3D p1 = obj1.p;
        Vector3D v1 = obj1.v;
        Point3D p2 = obj2.p;
        Vector3D v2 = obj2.v;
        Vector3D n = v1.crossProduct(v2);
        if (n.isZeroVector()) {
            return distance(p1, obj2);
        }
        return distance(p1, Plane(p2, n));
    }

    double distance(Line obj1, Plane obj2) {
        if (obj1.v.dotProduct(obj2.N) == 0) {
            return distance(obj1.p, obj2);
        }
        else {
            return 0;
        }
    }

    double distance(Ray obj1, Plane obj2) {
        if (obj1.V.dotProduct(obj2.N) == 0) {
            return distance(obj1.P, obj2);
        }
        else {
            return 0;
        }
    }

    double distance(Segment obj1, Plane obj2) {
        if (obj1.direction().dotProduct(obj2.N) == 0) {
            return distance(obj1.A, obj2);
        }
        else {
            return 0;
        }
    }

    std::tuple<Point3D, double, double, bool> intersectLineLine(Line line1, Line line2) {
        Point3D P1 = line1.p;
        Vector3D V1 = line1.v;
        Point3D P2 = line2.p;
        Vector3D V2 = line2.v;
        Vector3D P1P2 = P1.pointTo(P2);
        auto deno = V1.dy * V2.dx - V1.dx * V2.dy;
        if (deno != 0) {
            auto t1 = -(-P1P2.dy * V2.dx + P1P2.dx * V2.dy) / deno;
            auto t2 = -(-P1P2.dy * V1.dx + P1P2.dx * V1.dy) / deno;
            V1 = V1.amplified(t1);
            P1.x += V1.dx;
            P1.y += V1.dy;
            P1.z += V1.dz;
            P1.w += V1.dw;
            return std::make_tuple(P1, t1, t2, true);
        }
        else {
            deno = V1.dz * V2.dy - V1.dy * V2.dz;
            if (deno != 0) {
                auto t1 = -(-P1P2.dz * V2.dy + P1P2.dy * V2.dz) / deno;
                auto t2 = -(-P1P2.dz * V1.dy + P1P2.dy * V1.dz) / deno;
                V1 = V1.amplified(t1);
                P1.x += V1.dx;
                P1.y += V1.dy;
                P1.z += V1.dz;
                P1.w += V1.dw;
                return std::make_tuple(P1, t1, t2, true);
            }
        }
        return std::make_tuple(P1, 0, 0, false);
    }

    std::vector<std::shared_ptr<Point3D>> intersectSegmentPlane(Segment seg, Plane plane) {
        Point3D A = seg.A;
        Point3D B = seg.B;
        if (distance(A, plane) == 0.0 && distance(B, plane) == 0.0) {
            std::shared_ptr<Point3D> pt_A = std::make_shared<Point3D>(A);
            std::shared_ptr<Point3D> pt_B = std::make_shared<Point3D>(B);
            return { pt_A,pt_B };
        }
        Point3D P = plane.P;
        Vector3D N = plane.N;
        auto V = A.pointTo(B);
        auto PA = P.pointTo(A);
        if (V.dotProduct(N) == 0) {
            return {};
        }
        else {
            auto t = -(PA.dotProduct(N)) / V.dotProduct(N);
            if (t >= 0 && t <= 1) {
                V = V.amplified(t);
                A.x += V.dx;
                A.y += V.dy;
                A.z += V.dz;
                A.w += V.dw;
                std::shared_ptr<Point3D> pt = std::make_shared<Point3D>(A);
                return { pt };
            }
        }
        return {};
    }

    std::tuple<Point3D, bool> intersect(Line obj1, Line obj2) {
        auto result = intersectLineLine(obj1, obj2);
        bool is_exit = std::get<3>(result);
        Point3D p = std::get<0>(result);
        if (is_exit) {
            return std::make_tuple(p, is_exit);
        }
        else {
            return std::make_tuple(p, false);
        }
    }

    std::tuple<Point3D, bool>  intersect(Segment obj1, Segment obj2) {
        auto line1 = Line(obj1.A, obj1.direction());
        auto line2 = Line(obj2.A, obj2.direction());
        auto result = intersectLineLine(line1, line2);
        if (std::get<3>(result)) {
            if (std::get<1>(result) >= 0 && std::get<1>(result) <= obj1.length()) {
                if (std::get<2>(result) >= 0 && std::get<2>(result) <= obj2.length()) {
                    return std::make_tuple(std::get<0>(result), true);
                }
            }
        }
        return std::make_tuple(std::get<0>(result), false);
    }

    std::tuple<Point3D, bool>  intersect(Line obj1, Segment obj2) {
        auto line1 = obj1;
        auto line2 = Line(obj2.A, obj2.direction());
        auto result = intersectLineLine(line1, line2);
        if (std::get<3>(result)) {
            if (std::get<2>(result) >= 0 && std::get<2>(result) <= obj2.length()) {
                return std::make_tuple(std::get<0>(result), true);
            }
        }
        return std::make_tuple(std::get<0>(result), false);
    }

    std::tuple<Point3D, bool>  intersect(Line obj1, Plane obj2) {
        auto P0 = obj1.p;
        auto V = obj1.v;
        auto P1 = obj2.P;
        auto N = obj2.N;
        auto dotPro = V.dotProduct(N);
        if (dotPro != 0) {
            auto t = P0.pointTo(P1).dotProduct(N) / dotPro;
            V = V.amplified(t);
            P0.x += V.dx;
            P0.y += V.dy;
            P0.z += V.dz;
            P0.w += V.dw;
            return std::make_tuple(P0, true);
        }
        return std::make_tuple(P0, false);
    }

    std::shared_ptr<Point3D>  intersect(Segment obj1, Plane obj2) {
        return intersectSegmentPlane(obj1, obj2);

    }

    bool pointOnRay(Point3D p, Ray ray) {
        return false;
    }

    int pointInPolygon(Point3D p, Polyline polygon) {
        return 0;
    }
}


