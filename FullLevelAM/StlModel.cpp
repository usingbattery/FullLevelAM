//
// Created by MBP on 2023/4/18.
//

#include "StlModel.h"

StlModel::StlModel(std::vector<Triangle> trs) {
    triangles = trs;
    bound = {xMin, xMax, yMin, yMax, zMin, zMax};
//    bound.resize(6);
}

int StlModel::getFacetNumber() {
    return triangles.size();
}

std::vector<float> StlModel::getCoords(std::string line) {
    std::vector<float> ans(3);
    int len = line.size();
    ans[0] = line[len-3];
    ans[1] = line[len-2];
    ans[2] = line[len-1];
    return ans;
}

void StlModel::readStlFile(std::string filepath) {

}

void StlModel::extractFromVtkStlReader() {

}

std::vector<double> StlModel::getBound() {
    if(triangles.size() == 0){
        return bound;
    }
    else{
        xMin = triangles[0].A.x;
        xMax = triangles[0].A.x;
        yMin = triangles[0].A.y;
        yMax = triangles[0].A.y;
        zMin = triangles[0].A.z;
        zMax = triangles[0].A.z;
    }
    for(Triangle t : triangles){
        xMin = std::min({zMin, t.A.x, t.B.x, t.C.x});
        yMin = std::min({yMin, t.A.y, t.B.y, t.C.y});
        zMin = std::min({zMin, t.A.z, t.B.z, t.C.z});
        xMax = std::max({xMax, t.A.x, t.B.x, t.C.x});
        yMax = std::max({yMax, t.A.y, t.B.y, t.C.y});
        zMax = std::max({zMin, t.A.z, t.B.z, t.C.z});
    }
    bound = {xMin, xMax, yMin, yMax, zMin, zMax};
}
















