#pragma once

#include "Layer.h"

namespace nsp {

    class Cutter {

    public:

        Cutter(StlModel stlModel, double layerHeight = 1);

        Layer* layers;

        int layersNum;

    private:
        
        void init(double zMin, double zMax, double layerLength);

        void Cut(std::multimap <double, Triangle> triangles);
    };
}