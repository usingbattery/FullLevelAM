#include "Fun.h"

namespace nsp {

	int cmp_pntSmaller(const LinkPoint& lp1, const LinkPoint& lp2) {
		if (lp1.x < lp2.x) {
			return -1;
		}
		else if (lp1.x == lp2.x && lp1.y < lp2.y) {
			return -1;
		}
		else if (lp1.x == lp2.x && lp1.y == lp2.y && lp1.z < lp2.z) {
			return -1;
		}
		else if (lp1.x == lp2.x && lp1.y == lp2.y && lp1.z == lp2.z) {
			return 0;
		}
		else return 1;
	}
}