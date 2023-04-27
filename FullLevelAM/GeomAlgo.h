//
// Created by MBP on 2023/4/18.
//

#ifndef FULLLEVELAM_GEOMALGO_H
#define FULLLEVELAM_GEOMALGO_H

#include "Point3D.h"
#include "Line.h"
#include "Segment.h"
#include "Plane.h"
#include "Ray.h"
#include "Polyline.h"
namespace nsp {
    bool nearZero();

    double distance();

    Point3D intersectLineLine(Line line1, Line line2);

    Point3D intersectSegmentPlane(Segment seg, Plane plane);

    double intersect();

    bool pointOnRay(Point3D p, Ray ray);

    int pointInPolygon(Point3D p, Polyline polygon);
}
#endif //FULLLEVELAM_GEOMALGO_H
