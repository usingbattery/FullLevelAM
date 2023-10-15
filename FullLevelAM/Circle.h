#pragma once
#include "Polyline.h"

namespace nsp {
	class Circle
	{
	public:
		Circle(Polyline polyline= Polyline()) :selfpl(polyline) {};

		Polyline selfpl;
		//the starting point location
		int startIndex = 0;
		//true is -1,false is +1
		bool isReverse=false;

		//get i
		Point3D get(int i);
	};
}
