#include "Circle.h"

namespace nsp {

	Point3D Circle::get(int i) {
		if (isReverse) {
			return selfpl.points[(startIndex - i + selfpl.count()) % (selfpl.count())];
		}
		else {
			return selfpl.points[(startIndex + i + selfpl.count()) % (selfpl.count())];
		}
	}
}