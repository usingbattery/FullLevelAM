//
// Created by MBP on 2023/4/18.
//

#include "GeomAlgo.h"

bool nearZero(double x) {
    return abs(x)<epsilon;
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
    Point3D p = obj2.p;
    Point3D q = obj1;
    Vector3D v = obj2.v;
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
    double l = obj2.length();
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
    }else{
        return 0;
    }
}

double distance(Ray obj1, Plane obj2) {
    if (obj1.v.dotProduct(obj2.N) == 0) {
        return distance(obj1.p, obj2);
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

Point3D intersectLineLine(Line line1, Line line2) {
    return Point3D();
}

Point3D intersectSegmentPlane(Segment seg, Plane plane) {
    return Point3D();
}

double intersect() {
    return 0;
}

bool pointOnRay(Point3D p, Ray ray) {
    return false;
}

int pointInPolygon(Point3D p, Polyline polygon) {
    return 0;
}
