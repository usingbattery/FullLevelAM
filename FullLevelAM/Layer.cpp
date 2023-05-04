//
// Created by Lo on 2023/4/24.
//

#include "Layer.h"
namespace nsp {
	
	Layer::Layer(std::vector<Triangle> ts){
		this->triangles=new Triangle[ts.size()];
	}
}