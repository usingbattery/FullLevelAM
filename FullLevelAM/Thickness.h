#pragma once

#include "Layer.h"

namespace nsp {


	class Thickness {

	public:

		Layer* layerUp;
		Layer* layerDown;

		Thickness(Layer* layerUp_ =nullptr, Layer* layerDown_ = nullptr) : layerUp(layerUp_), layerDown(layerDown_) {}
	};

}

