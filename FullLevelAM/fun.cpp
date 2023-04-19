//
// Created by MBP on 2023/4/18.
//

#include "fun.h"
void writePolyline(std::string path, Polyline polyline, bool clear_txt) {
    std::ofstream pl_outfile;
    pl_outfile.open(path, std::ios::app);

}

Polyline readPolyline(std::string path) {
    return Polyline();
}

Segment intersectTrianglePlane(Triangle triangle, Plane plane) {
    Segment AB(triangle.A, triangle.B);
    Segment AC(triangle.A, triangle.C);
    Segment BC(triangle.B, triangle.C);
    Point3D c1 = intersectSegmentPlane(AB, plane);
    Point3D c2 = intersectSegmentPlane(AC, plane);
    Point3D c3 = intersectSegmentPlane(BC, plane);


}
