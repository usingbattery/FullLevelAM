#pragma once

#include "Triangle.h"

namespace nsp {

	struct CutTriangle {
		int index;
		double z;
		Triangle* triangle;
	};
}