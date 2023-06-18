#include "File.h"
#include "Point3D.h"
#include "StlModel.h"
#include "Cutter.h"
#include "VtkAdaptor.h"
#include "fun.h"
#include "GeomAlgo.h"
using namespace nsp;

int main() {

	//VtkAdaptor vtkAdaptor;
	//vtkAdaptor.setBackgroundColor(0.95, 0.95, 0.95);
	//vtkAdaptor.drawAxes();

	StlModel s("zdd-asc.STL");
	std::vector heights = { 1.0,2.0,4.0 };
	Cutter c(s, heights, true);

	for (int i = 0; i < c.layers.size(); i++) {
		std::cout << c.layers[i].plane.P.z << std::endl;
		for (Segment segment : c.layers[i].segments) {
			std::cout << "\t" << segment.toString() << std::endl;
			//vtkAdaptor.drawSegment(segment)->GetProperty()->SetColor(1, 0, 0);
		}
	}
	//vtkAdaptor.display();
}