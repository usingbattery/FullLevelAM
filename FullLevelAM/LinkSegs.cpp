#include "LinkSegs.h"
#include <map>
#include <algorithm>

namespace nsp {

	std::vector<Polyline> linkSegs(std::vector<Segment> segments) {
		std::vector<LinkPoint> linkPoints(2 * segments.size());
		int i = 0;
		for (const Segment& segment : segments) {
			linkPoints[i] = (LinkPoint(segment.A));
			linkPoints[i + 1] = (LinkPoint(segment.B));
			linkPoints[i].other = &linkPoints[i + 1];
			linkPoints[i + 1].other = &linkPoints[i];
			i += 2;
		}
		std::vector<Polyline> polylines;
		Polyline polyline;
		LinkPoint* begin = &(linkPoints[0]);
		LinkPoint* end = (*begin).other;
		polyline.addPoint((*begin).self);
		polyline.addPoint((*end).self);
		(*begin).used = true;
		(*end).used = true;
		int usedSegmentNum = 1;
		bool hasFound = true;
		while (usedSegmentNum < segments.size()) {
			if ((*end).self.isCoincide(polyline.point(0))|| !hasFound) {
				polylines.push_back(polyline);
				polyline = Polyline();
				for (int i = 1; i < linkPoints.size(); i++) {
					if (!linkPoints[i].used) {
						begin = &(linkPoints[i]);
						end = (*begin).other;
						polyline.addPoint((*begin).self);
						polyline.addPoint((*end).self);
						(*begin).used = true;
						(*end).used = true;
						usedSegmentNum++;
						break;
					}
				}
			}
			hasFound = false;
			for (int i = 1; i < linkPoints.size(); i++) {
				if (!linkPoints[i].used && (*end).self.isCoincide(linkPoints[i].self)) {
					hasFound = true;
					begin = &(linkPoints[i]);
					end = (*begin).other;
					polyline.addPoint((*end).self);
					(*begin).used = true;
					(*end).used = true;
					usedSegmentNum++;
					break;
				}
			}
		}
		polylines.push_back(polyline);
		polyline = Polyline();
		return polylines;

		//std::sort(linkPoints.begin(), linkPoints.end());
		//for (int j = 0; j < linkPoints.size();j++) {
		//	linkPoints[j].index = j;
		//}
		//int usedSegmentNum = 0;
		//LinkPoint begin = linkPoints[0];
		//LinkPoint end = *(begin.other);
		//Polyline polyline;
		//polyline.addPoint(begin.self);
		//polyline.addPoint(end.self);
		//while (usedSegmentNum < segments.size()) {
		//	int k = end.index;
		//	if (k > 0 && linkPoints[k - 1].self.isCoincide(linkPoints[k].self)) {
		//		begin = linkPoints[k - 1];
		//	}
		//}
	}
}