//
// Created by MBP on 2023/4/18.
//

#include "StlModel.h"
#include <algorithm>
namespace nsp {

    StlModel::StlModel(std::vector<Triangle> trs) {
        triangles = trs;
        bound = {xMin, xMax, yMin, yMax, zMin, zMax};
//    bound.resize(6);
    }

    int StlModel::getFacetNumber() {
        return triangles.size();
    }

    std::vector<double> StlModel::getCoords(std::string line) {
        std::vector<double> ans(3);
        int len = line.size();
        ans[0] = line[len - 3];
        ans[1] = line[len - 2];
        ans[2] = line[len - 1];
        return ans;
    }

    void StlModel::readStlFile(std::string filepath) {

        File f;
        double dx = 0, dy = 0, dz = 0;
        Point3D A, B, C;
        Vector3D N;
        while(true){
            try{
                std::string line = "";
                std::getline(f.infile, line);
                if(!line.empty() && line.back() == '\n'){
                    line.pop_back();
                }
                if(line.empty()) break;
                if(line.substr(0, 12) == "facet normal"){
                    std::vector<double> vec_tmp = getCoords(line);
                    dx = vec_tmp[0];
                    dy = vec_tmp[1];
                    dz = vec_tmp[2];
                    N = Vector3D(dx, dy, dz);
                    std::getline(f.infile, line);
                    A.x = getCoords(line)[0];
                    A.y = getCoords(line)[1];
                    A.z = getCoords(line)[2];

                    std::getline(f.infile, line);
                    B.x = getCoords(line)[0];
                    B.y = getCoords(line)[1];
                    B.z = getCoords(line)[2];

                    std::getline(f.infile, line);
                    C.x = getCoords(line)[0];
                    C.y = getCoords(line)[1];
                    C.z = getCoords(line)[2];
                    triangles.push_back(Triangle(A, B, C, N));
                }
            }
            catch(...){
                std::cout << "void StlModel::readStlFile(std::string filepath) 出现异常";
            }
        }
        f.~File();
    }

    void StlModel::extractFromVtkStlReader() {

    }

    std::vector<double> StlModel::getBound() {
        if (triangles.size() == 0) {
            return bound;
        } else {
            xMin = triangles[0].A.x;
            xMax = triangles[0].A.x;
            yMin = triangles[0].A.y;
            yMax = triangles[0].A.y;
            zMin = triangles[0].A.z;
            zMax = triangles[0].A.z;
        }
        for (Triangle t: triangles) {
            xMin = std::min({zMin, t.A.x, t.B.x, t.C.x});
            yMin = std::min({yMin, t.A.y, t.B.y, t.C.y});
            zMin = std::min({zMin, t.A.z, t.B.z, t.C.z});
            xMax = std::max({xMax, t.A.x, t.B.x, t.C.x});
            yMax = std::max({yMax, t.A.y, t.B.y, t.C.y});
            zMax = std::max({zMin, t.A.z, t.B.z, t.C.z});
        }
        bound = {xMin, xMax, yMin, yMax, zMin, zMax};
    }
}















