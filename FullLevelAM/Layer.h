#pragma once

#include <vector>
#include "Plane.h"
#include "Segment.h"
#include "StlModel.h"

namespace nsp {

    class Layer {

    public:

        //current layer
        Plane plane;
        //intersected segment
        std::vector<Segment> segmens;
        //intersected segment in order
        std::vector<Segment> contours;

        Layer() {}

        void setPlane(Plane plane_);

        std::vector<Triangle> intersectStlLayer(std::vector<Triangle> preTriangles, std::multimap <double, Triangle> restTriangles, std::multimap <double, Triangle>::iterator it);

        void intersectTriangleLayer(std::vector<Triangle> preTriangles);

    private:

    };
}