#pragma once
#include "Segment.h"
#include <map>
#include "LinkPoint.h"
namespace nsp {
	class LinkSegs_dlook
	{
	public:
		LinkSegs_dlook(std::vector<Segment> segments);

		std::vector<Segment> segs;
		std::vector<Segment> contours;
		std::vector<Segment> polys;

		std::map<std::pair<double, double>, std::vector<LinkPoint>> createLpDic();

		LinkPoint findUnusedPnt(std::map<std::pair<double, double>, std::vector<LinkPoint>> dic);
	};
}
