#pragma once

#include "Layer.h"

namespace nsp {

    class Layers {

    public:

        Layers(StlModel stlModel, double layerHeight = 1);

        Layer* layers;

        int layersNum;

    private:
        
        void initLayers(double zMin, double zMax, double layerLength);

        void intersectStlLayers(std::multimap <double, Triangle> triangles);
    };
}