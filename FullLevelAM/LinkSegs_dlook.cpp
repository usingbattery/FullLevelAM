#include "LinkSegs_dlook.h"
namespace nsp {

	LinkSegs_dlook::LinkSegs_dlook(std::vector<Segment> segments) {
		segs = segments;
	}

	std::map<std::pair<double, double>, std::vector<LinkPoint>> LinkSegs_dlook::createLpDic() {
		std::map<std::pair<double, double>, std::vector<LinkPoint>> dic;
		for (Segment& seg : segs) {
			LinkPoint lp1 = LinkPoint(seg.A);
			LinkPoint lp2 = LinkPoint(seg.B);
			lp1.other = &lp2;
			lp2.other = &lp1;

			if (!dic.count(std::make_pair(lp1.x, lp1.y))) {
				dic.insert(std::make_pair(std::make_pair(lp1.x, lp1.y), std::vector<LinkPoint> {}));
			}
			dic[std::make_pair(lp1.x, lp1.y)].push_back(lp1);

			if (!dic.count(std::make_pair(lp2.x, lp2.y))) {
				dic.insert(std::make_pair(std::make_pair(lp2.x, lp2.y), std::vector<LinkPoint> {}));
			}
			dic[std::make_pair(lp2.x, lp2.y)].push_back(lp2);
		}
		return dic;
	}

	LinkPoint LinkSegs_dlook::findUnusedPnt(std::map<std::pair<double, double>, std::vector<LinkPoint>> dic) {
		for (auto& [first, pnts] : dic) {
			for (LinkPoint& pnt : pnts) {
				if (pnt.used == false) {
					return pnt;
				}
			}
		}
		return LinkPoint();
	}

	//return next_LinkPoint
	LinkPoint LinkSegs_dlook::findNextPnt(LinkPoint p, std::map<std::pair<double, double>, std::vector<LinkPoint>> dic) {
		auto other = p.other;
		std::pair<double, double> keys(other->x, other->y);
		std::vector<LinkPoint> values;
		values.push_back(other->toPoint3D());
		dic[keys] = values;
		LinkPoint difPnt;
		for (auto iter = dic.begin(); iter != dic.end(); iter++) {
			for (auto& c : iter->second) {
				if (&c != other) {
					difPnt = c;
				}
			}
		}
		return difPnt;
	}

	//
	void LinkSegs_dlook::Link() {
		std::map<std::pair<double, double>, std::vector<LinkPoint>> dic = createLpDic();
		while (1) {
			auto p = findUnusedPnt(dic);
			if (p == LinkPoint())break;
			auto poly = Polyline();
			while (1) {
				poly.addPoint(p.toPoint3D());
				p.used = true;
				p.other->used = true;
				p = findNextPnt(p, dic);
				if (poly.isClosed()) {
					contours.push_back(poly);
					break;
				}
				if (p == LinkPoint()) {
					polys.push_back(poly);
					break;
				}
			}
		}
	}
}