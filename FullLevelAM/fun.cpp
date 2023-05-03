//
// Created by MBP on 2023/4/18.
//

#include "fun.h"
namespace nsp {
    void writePolyline(std::string path, Polyline polyline, bool clear_txt) {
//        std::ofstream pl_outfile;
//        pl_outfile.open(path, std::ios::app);

    }

    Polyline readPolyline(std::string path) {
        return Polyline();
    }

    Segment intersectTrianglePlane(Triangle triangle, Plane plane) {
        Segment AB(triangle.A, triangle.B);
        Segment AC(triangle.A, triangle.C);
        Segment BC(triangle.B, triangle.C);

        Point3D c1 = std::get<0>(intersectSegmentPlane(AB, plane));
        Point3D c2 = std::get<0>(intersectSegmentPlane(AC, plane));
        Point3D c3 = std::get<0>(intersectSegmentPlane(BC, plane));
        if(c1.isIdentical(Point3D())){
            if(c2.isIdentical(Point3D()) && c3.isIdentical(Point3D())){
                if(c2.distance(c3) != 0.0){
                    return Segment(c2, c3);
                }
            }
        }
        else if(c2.isIdentical(Point3D())){
            if(c1.isIdentical(Point3D()) && c3.isIdentical(Point3D())){
                if(c1.distance(c3) != 0.0){
                    return Segment(c1, c3);
                }
            }
        }
        else if(c3.isIdentical(Point3D())){
            if(c1.isIdentical(Point3D()) && c2.isIdentical(Point3D())){
                if(c1.distance(c2) != 0.0){
                    return Segment(c1, c2);
                }
            }
        }
        else{
            if(c1.isIdentical(c2)){
                return Segment(c1, c3);
            }
            else{
                return Segment(c1, c2);
            }
        }
        return Segment(Point3D(), Point3D());
    }
}