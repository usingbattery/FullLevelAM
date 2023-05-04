#include"Segment.h"
namespace nsp {

//Initialize Segment
    Segment::Segment(Point3D a, Point3D b) {
        this->A = a.clone();
        this->B = b.clone();
    }

//Distance from point A to point B
    double Segment::length() {
        return A.distance(B);
    }

//Direction vector from point A to point B
    Vector3D Segment::direction() {
        return A.pointTo(B);
    }


//Swap the two ends of a line segment
    void Segment::swap() {
        Point3D temp;
        temp = A;
        A = B;
        B = temp;
    }

    bool Segment::operator==(Segment segment) {
        return (A == segment.A && B == segment.A) || (B == segment.A && A == segment.B);
    }

    bool Segment::operator!=(Segment segment) {
        return !this->operator==(segment);
    }
}