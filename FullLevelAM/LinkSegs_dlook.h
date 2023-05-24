#pragma once
#include "Segment.h"
#include <map>
#include "LinkPoint.h"
#include "Polyline.h"
namespace nsp {
	class LinkSegs_dlook
	{
	public:
		LinkSegs_dlook(std::vector<Segment> segments);

		std::vector<Segment> segs;
		std::vector<Polyline> contours;
		std::vector<Polyline> polys;

		std::map<std::pair<double, double>, std::vector<LinkPoint>> createLpDic();

		LinkPoint findUnusedPnt(std::map<std::pair<double, double>, std::vector<LinkPoint>> dic);

		LinkPoint findNextPnt(LinkPoint p, std::map<std::pair<double, double>, std::vector<LinkPoint>> dic);
		void Link();
	};
}
