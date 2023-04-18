//
// Created by MBP on 2023/4/18.
//

#include "Polyline.h"
void Polyline::makeCCW() {
    if(this->getArea()){
        this->reverse();
    }
}

void Polyline::makeCW() {
    if(this->getArea()){
        this->reverse();
    }
}

bool Polyline::isCCW() {
    if(this->getArea() > 0) return true;
    return false;
}

void Polyline::translate(Vector3D vec) {
    for(int i = 0; i < points.size(); i++){
        points[i].translate(vec);
    }
}

bool Polyline::appendSegment(Segment seg) {
    if(this->count() == 0){
        this->points.push_back(seg.A);
        this->points.push_back(seg.B);
    }
    else{
        if(seg.A.isCoincide(points.back())){
            this->points.push_back(seg.B);
        }
        else if(seg.B.isCoincide(points.back())){
            this->points.push_back(seg.A);
        }
        else if(seg.A.isCoincide(points.front())){

        }
        else if(seg.B.isCoincide(points.front())){

        }
        else{
            return false;
        }
    }
    return true;
}
