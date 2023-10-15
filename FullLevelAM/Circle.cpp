#include "Circle.h"

namespace nsp {

	Point3D Circle::get(int i) {
		int index = startIndex;
		if (isReverse) {
			index -= i;
		}
		else {
			index += i;
		}
		index = index % (selfpl.count());
		index = (index+ (selfpl.count())) % (selfpl.count());
		return selfpl.points[index];
	}
}