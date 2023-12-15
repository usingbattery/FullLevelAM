#include "File.h"
#include "Point3D.h"
#include "StlModel.h"
#include "Cutter.h"
#include "VtkAdaptor.h"
#include "GeomAlgo.h"
#include "LinkSegs.h"

using namespace nsp;

int main() {

	StlModel s("zdd-asc.STL");

	//std::vector<double> heights = {0,100,200};
	std::vector<double> heights ;
	for (double h = s.bound[2] + 1; h < s.bound[5]; h += 10) {
		heights.push_back(h);
	}
	Cutter c(&s, heights);
	while (c.forward());

	//for (Layer& layer:c.layers) {
	//	std::cout << layer.plane.P.z << std::endl;
	//	for (int j = 0; j<3 && j < layer.segments.size();j++) {
	//		std::cout << "\t" << layer.segments[j].toString() << std::endl;
	//	}
	//	std::cout << "\t" << "..." << std::endl;
	//}

	VtkAdaptor vtkAdaptor;
	vtkAdaptor.setBackgroundColor(0.95, 0.95, 0.95);
	vtkAdaptor.drawAxes();
	for (int i = 0; i < c.thickness.size(); i++) {
		std::vector<vtkNew<vtkActor>> actors = vtkAdaptor.drawThickness(c.thickness[i]);
		actors[0]->GetProperty()->SetColor(0, 0, 1);
		if (actors.size() > 1) {
			actors[1]->GetProperty()->SetColor(0, 1, 0);
		}
	}
	vtkAdaptor.display();

}