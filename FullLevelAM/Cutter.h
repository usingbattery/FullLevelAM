#pragma once

#include "Layer.h"

namespace nsp {

    class Cutter {

    public:

        Cutter(StlModel stlModel, double* heights, int heightNum, bool isSorted = false);

        Layer* layers;

        int layersNum;

    private:

        void init(double* heights, int heightNum);

        void Cut(std::multimap <double, Triangle> triangles);
    };
}