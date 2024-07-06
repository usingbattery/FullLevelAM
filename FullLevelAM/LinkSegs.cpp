#include "LinkSegs.h"
#include <map>
#include <algorithm>

namespace nsp {

	std::vector<double> linkSegs(std::vector<Segment> segments, std::vector<Polyline>* polylines, std::vector<std::vector<Polar>>* polars) {
		polylines->clear();
		polars->clear();
		std::vector<double> minXs;
		if (segments.size() == 0) {
			return minXs;
		}
		std::vector<LinkPoint> linkPoints(2 * segments.size());
		int i = 0;
		for (const Segment& segment : segments) {
			linkPoints[i] = LinkPoint(segment.A);
			linkPoints[i + 1] = LinkPoint(segment.B);
			linkPoints[i].other = &linkPoints[i + 1];
			linkPoints[i + 1].other = &linkPoints[i];
			i += 2;
		}
		Polyline polyline;
		std::vector<Polar> polar;
		LinkPoint* begin = &(linkPoints[0]);
		LinkPoint* end = (*begin).other;
		polyline.addPoint((*begin).self);
		polar.push_back(point3DXYZToPolar(begin->self));
		minXs.push_back((*begin).self.x);
		polyline.addPoint((*end).self);
		polar.push_back(point3DXYZToPolar(end->self));
		if ((*end).self.x < minXs[(*polylines).size()]) {
			minXs[(*polylines).size()] = (*end).self.x;
		}
		(*begin).used = true;
		(*end).used = true;
		int usedSegmentNum = 1;
		bool hasFound = true;
		while (usedSegmentNum < segments.size()) {
			if ((*end).self.isCoincide(polyline.point(0)) || !hasFound) {
				(*polylines).push_back(polyline);
				polars->push_back(polar);
				polyline = Polyline();
				polar.clear();
				for (int i = 1; i < linkPoints.size(); i++) {
					if (!linkPoints[i].used) {
						begin = &(linkPoints[i]);
						end = (*begin).other;
						polyline.addPoint((*begin).self);
						polar.push_back(point3DXYZToPolar(begin->self));
						minXs.push_back((*begin).self.x);
						polyline.addPoint((*end).self);
						polar.push_back(point3DXYZToPolar(end->self));
						if ((*end).self.x < minXs[(*polylines).size()]) {
							minXs[(*polylines).size()] = (*end).self.x;
						}
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
					polar.push_back(point3DXYZToPolar(end->self));
					if ((*end).self.x < minXs[(*polylines).size()]) {
						minXs[(*polylines).size()] = (*end).self.x;
					}
					(*begin).used = true;
					(*end).used = true;
					usedSegmentNum++;
					break;
				}
			}
		}
		(*polylines).push_back(polyline);
		polars->push_back(polar);
		return minXs;
	}
	Polar point3DXYZToPolar(Point3D point) {
		double angle = (double)atan2(point.y, point.x) / (2 * acos(-1)) * 360;
		if (angle < 0) {
			angle += 360;
		}
		double len = sqrt(point.x * point.x + point.y * point.y);
		return { angle,len,point.z };
	}
}