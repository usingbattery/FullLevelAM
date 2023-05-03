//
// Created by Lo on 2023/4/24.
//

#ifndef FULLLEVELAM_LAYER_H
#define FULLLEVELAM_LAYER_H

#include <vector>
#include <map>
#include "Segment.h"
#include "Triangle.h"

namespace nsp {

    class Layer {

    public:
        //current layer
        int z = 0;
        //intersected segment
        std::vector<Segment> segmens;
        //intersected segment in order
        std::vector<Segment> contours;

        Layer(std::multimap <double, Triangle> ts);

    private:
        std::multimap <double, Triangle> triangles;
    };
}

#endif //FULLLEVELAM_LAYER_H
