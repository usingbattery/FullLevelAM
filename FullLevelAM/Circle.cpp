#include "Circle.h"

namespace nsp {

	Circle::Circle(Polyline polyline)
	{
		selfpl = polyline;
	}

	Point3D Circle::get(int i) {
		if (isReverse) {
			return selfpl.points[(startIndex - i + selfpl.count()) % (selfpl.count())];
		}
		else {
			return selfpl.points[(startIndex + i + selfpl.count()) % (selfpl.count())];
		}
	}
}