#include "Triangle.h"
#include <algorithm>

namespace nsp {

    std::string Triangle::toString() {
        std::string res = "Triangle:";
        return res + A.toString() +" " + B.toString() + " " + C.toString();
    }

    double Triangle::zMinPnt() {
        return std::min({A.z, B.z, C.z});
    }

    double Triangle::zMaxPnt() {
        return std::max({A.z, B.z, C.z});
    }

    bool Triangle::operator==(Triangle t) {
        return A == t.A && B == t.B && C == t.C && N == t.N;
    }

    bool Triangle::operator!=(Triangle t) {
        return !this->operator==(t);
    }
}