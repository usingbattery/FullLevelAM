//
// Created by MBP on 2023/4/18.
//

#include "Triangle.h"

double Triangle::zMinPnt() {
    return min({A.z, B.z, C.z});
}

double Triangle::zMaxPnt() {
    return max({A.z, B.z, C.z});
}
