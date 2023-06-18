#pragma once

#include "Layer.h"

namespace nsp {

    class Cutter {

    public:

        Cutter(StlModel stlModel, double distance);
        Cutter(StlModel stlModel, int layersNum);
        Cutter(StlModel stlModel, double* heights, int heightNum, bool isSorted = false);

        Layer* layers;

        int layersNum;

    private:

        void init(double zMin, double zMax, double distance);
        void init(double* heights, int heightNum);

        void Cut(std::multimap <double, Triangle> triangles);
    };
}