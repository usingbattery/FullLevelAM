//
// Created by MBP on 2023/4/18.
//

#ifndef FULLLEVELAM_PLANE_H
#define FULLLEVELAM_PLANE_H
#include <vector>
#include "Line.h"
namespace nsp {

	class Plane {

	public:

		Plane(Point3D p = Point3D(), Vector3D n = Vector3D()) : P(p), N(n) {}

		std::string toString();

		//获取标准直线方程Ax+By+Cz+D = 0的参数
		std::vector<double> toFormula();

		//返回3D点的z平面
		Plane zPlane(double z);

		//返回两平面求交得到的线段
		Line intersect(Plane pl);

		//平面经过的点
		Point3D P;
		//平面法向量
		Vector3D N;

		bool operator==(Plane plane);

		bool operator!=(Plane plane);

	private:

	};
}
#endif //GCODE_PLANE_H
