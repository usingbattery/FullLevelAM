#include <cmath>
#include "GeomAlgo.h"

namespace nsp {

	bool nearZero(double x) {
		return abs(x) < epsilon;
	}

	double distance(Point3D obj1, Line obj2) {
		Point3D p = obj2.p;
		Point3D q = obj1;
		Vector3D v = obj2.v;
		double t = p.pointTo(q).dotProduct(v);
		Point3D r = p + v.amplified(t);
		return q.distance(r);
	}

	double distance(Point3D obj1, Ray obj2) {
		Point3D p = obj2.P;
		Point3D q = obj1;
		Vector3D v = obj2.V;
		double t = p.pointTo(q).dotProduct(v);
		if (t >= 0) {
			Point3D r = p + v.amplified(t);
			return q.distance(r);
		}
		return q.distance(p);
	}

	double distance(Point3D obj1, Segment obj2) {
		Point3D q = obj1;
		Point3D p = obj2.A;
		Point3D p1 = obj2.B;
		Vector3D v = obj2.direction().normalized();
		auto l = obj2.length();
		double t = p.pointTo(q).dotProduct(v);
		if (t < 0) {
			return q.distance(p);
		}
		else if (t >= l) {
			return q.distance(p1);
		}
		else {
			Point3D r = p + v.amplified(t);
			return q.distance(r);
		}
	}

	double distance(Point3D obj1, Plane obj2) {
		Point3D p = obj2.P;
		Point3D q = obj1;
		Vector3D n = obj2.N;
		double angle = n.getAngle(p.pointTo(q));
		return p.distance(q) * cos(angle);
	}

	double distance(Line obj1, Line obj2) {
		Point3D p1 = obj1.p;
		Vector3D v1 = obj1.v;
		Point3D p2 = obj2.p;
		Vector3D v2 = obj2.v;
		Vector3D n = v1.crossProduct(v2);
		if (n.isZeroVector()) {
			return distance(p1, obj2);
		}
		return distance(p1, Plane(p2, n));
	}

	double distance(Line obj1, Plane obj2) {
		if (obj1.v.dotProduct(obj2.N) == 0) {
			return distance(obj1.p, obj2);
		}
		else {
			return 0;
		}
	}

	double distance(Ray obj1, Plane obj2) {
		if (obj1.V.dotProduct(obj2.N) == 0) {
			return distance(obj1.P, obj2);
		}
		else {
			return 0;
		}
	}

	double distance(Segment obj1, Plane obj2) {
		if (obj1.direction().dotProduct(obj2.N) == 0) {
			return distance(obj1.A, obj2);
		}
		else {
			return 0;
		}
	}

	std::tuple<Point3D, double, double, bool> intersect(Line line1, Line line2) {
		Point3D P1 = line1.p;
		Vector3D V1 = line1.v;
		Point3D P2 = line2.p;
		Vector3D V2 = line2.v;
		Vector3D P1P2 = P1.pointTo(P2);
		auto deno = V1.dy * V2.dx - V1.dx * V2.dy;
		if (deno != 0) {
			auto t1 = -(-P1P2.dy * V2.dx + P1P2.dx * V2.dy) / deno;
			auto t2 = -(-P1P2.dy * V1.dx + P1P2.dx * V1.dy) / deno;
			V1 = V1.amplified(t1);
			P1.x += V1.dx;
			P1.y += V1.dy;
			P1.z += V1.dz;
			return std::make_tuple(P1, t1, t2, true);
		}
		else {
			deno = V1.dz * V2.dy - V1.dy * V2.dz;
			if (deno != 0) {
				auto t1 = -(-P1P2.dz * V2.dy + P1P2.dy * V2.dz) / deno;
				auto t2 = -(-P1P2.dz * V1.dy + P1P2.dy * V1.dz) / deno;
				V1 = V1.amplified(t1);
				P1.x += V1.dx;
				P1.y += V1.dy;
				P1.z += V1.dz;
				return std::make_tuple(P1, t1, t2, true);
			}
		}
		return std::make_tuple(P1, 0, 0, false);
	}

	std::tuple<Point3D, bool>  intersect(Segment obj1, Segment obj2) {
		auto line1 = Line(obj1.A, obj1.direction());
		auto line2 = Line(obj2.A, obj2.direction());
		auto result = intersect(line1, line2);
		if (std::get<3>(result)) {
			if (std::get<1>(result) >= 0 && std::get<1>(result) <= obj1.length()) {
				if (std::get<2>(result) >= 0 && std::get<2>(result) <= obj2.length()) {
					return std::make_tuple(std::get<0>(result), true);
				}
			}
		}
		return std::make_tuple(std::get<0>(result), false);
	}

	std::tuple<Point3D, bool>  intersect(Line obj1, Segment obj2) {
		auto line1 = obj1;
		auto line2 = Line(obj2.A, obj2.direction());
		auto result = intersect(line1, line2);
		if (std::get<3>(result)) {
			if (std::get<2>(result) >= 0 && std::get<2>(result) <= obj2.length()) {
				return std::make_tuple(std::get<0>(result), true);
			}
		}
		return std::make_tuple(std::get<0>(result), false);
	}

	std::tuple<Point3D, bool>  intersect(Line obj1, Plane obj2) {
		auto P0 = obj1.p;
		auto V = obj1.v;
		auto P1 = obj2.P;
		auto N = obj2.N;
		auto dotPro = V.dotProduct(N);
		if (dotPro != 0) {
			auto t = P0.pointTo(P1).dotProduct(N) / dotPro;
			V = V.amplified(t);
			P0.x += V.dx;
			P0.y += V.dy;
			P0.z += V.dz;
			return std::make_tuple(P0, true);
		}
		return std::make_tuple(P0, false);
	}

	std::vector<std::shared_ptr<Point3D>>  intersect(Segment seg, Plane plane) {
		Point3D A = seg.A;
		Point3D B = seg.B;
		if (nearZero(distance(A, plane)) && nearZero(distance(B, plane))) {
			std::shared_ptr<Point3D> pt_A = std::make_shared<Point3D>(A);
			std::shared_ptr<Point3D> pt_B = std::make_shared<Point3D>(B);
			return { pt_A,pt_B };
		}
		else if (nearZero(distance(A, plane))) {
			std::shared_ptr<Point3D> pt_A = std::make_shared<Point3D>(A);
			return { pt_A };
		}
		else if (nearZero(distance(B, plane))) {
			std::shared_ptr<Point3D> pt_B = std::make_shared<Point3D>(B);
			return { pt_B };
		}
		Vector3D N = plane.N;
		auto V = A.pointTo(B);
		if (V.dotProduct(N) == 0) {
			return {};
		}
		Point3D P = plane.P;
		auto PA = P.pointTo(A);
		auto t = -(PA.dotProduct(N)) / V.dotProduct(N);
		if (t >= 0 && t <= 1) {
			V = V.amplified(t);
			A.x += V.dx;
			A.y += V.dy;
			A.z += V.dz;
			std::shared_ptr<Point3D> pt = std::make_shared<Point3D>(A);
			return { pt };
		}
		return {};
	}

	std::vector<Segment> intersect(Triangle triangle, Plane plane) {
		if (plane.P.z < triangle.zMinPnt() || plane.P.z > triangle.zMaxPnt()) {
			return { };
		}
		Segment AB(triangle.A, triangle.B);
		Segment AC(triangle.A, triangle.C);
		Segment BC(triangle.B, triangle.C);
		std::vector<std::shared_ptr<Point3D>> C1 = intersect(AB, plane);
		std::vector<std::shared_ptr<Point3D>> C2 = intersect(AC, plane);
		std::vector<std::shared_ptr<Point3D>> C3 = intersect(BC, plane);
		if (C1.size() + C2.size() + C3.size() > 4) {
			return { AB, AC, BC };
		}
		if (C1.size() == 2 ) return { AB };
		if (C2.size() == 2 ) return { AC };
		if (C3.size() == 2 ) return { BC };
		std::shared_ptr<Point3D> c1 = nullptr;
		if (!C1.empty()) c1 = C1[0];
		std::shared_ptr<Point3D> c2 = nullptr;
		if (!C2.empty()) c2 = C2[0];
		std::shared_ptr<Point3D> c3 = nullptr;
		if (!C3.empty()) c3 = C3[0];
		if (c1 == nullptr) {
			if (c2 != nullptr && c3 != nullptr) {
				//if(c2->distance(*c3) != 0.0){
				return { Segment(*c2, *c3) };
				//}
			}
		}
		else if (c2 == nullptr) {
			if (c1 != nullptr && c3 != nullptr) {
				//if(c1->distance(*c3) != 0.0){
				return { Segment(*c1, *c3) };
				//}
			}
		}
		else if (c3 == nullptr) {
			if (c1 != nullptr && c2 != nullptr) {
				//if(c1->distance(*c2) != 0.0){
				return { Segment(*c1, *c2) };
				//}
			}
		}
		else if (c1 != nullptr && c2 != nullptr && c3 != nullptr) {
			if (c1->isIdentical(*c2)) {
				return { Segment(*c1, *c3) };
			}
			else {
				return { Segment(*c1, *c2) };
			}
		}
		return { };
	}

}
