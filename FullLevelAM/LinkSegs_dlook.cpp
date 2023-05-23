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
}