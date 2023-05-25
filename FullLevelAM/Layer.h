#pragma once

#include "Plane.h"
#include "Segment.h"
#include "StlModel.h"

namespace nsp {

    class Layer {

    public:

        //current layer
        Plane plane;
        //intersected segment
        std::vector<Segment> segments;
        //intersected segment in order
        std::vector<Segment> contours;

        Layer() {}

        void setPlane(Plane plane_);

        std::vector<Triangle> intersectStlLayer(std::vector<Triangle> preTriangles, std::multimap <double, Triangle>* triangles, std::multimap <double, Triangle>::iterator* it);

    private:

    };
}