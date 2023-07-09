#include "File.h"
#include "Point3D.h"
#include "StlModel.h"
#include "Cutter.h"
#include "VtkAdaptor.h"
#include "fun.h"
#include "GeomAlgo.h"
#include "LinkSegs_dlook.h"

using namespace nsp;

int main() {

	//LinkSegs_dlook l(std::vector<Segment>{
	//	Segment(Point3D(0, 0, 1), Point3D(0, 1, 1)),
	//		Segment(Point3D(0, 1, 1), Point3D(1, 0, 1)),
	//		Segment(Point3D(1, 0, 1), Point3D(0, 0, 1))
	//});

	StlModel s("zdd-asc.STL");
	std::vector<double> heights = {100,120,140,90,80};
	//for (double h = s.bound[2]; h < s.bound[5]; h += 20) {
	//	heights.push_back(h);
	//}
	Cutter c(&s, heights);
	
	for (Layer& layer:c.layers) {
		std::cout << layer.plane.P.z << std::endl;
		for (int j = 0; j<3 && j < layer.segments.size();j++) {
			std::cout << "\t" << layer.segments[j].toString() << std::endl;
		}
	}

	VtkAdaptor vtkAdaptor;
	vtkAdaptor.setBackgroundColor(0.95, 0.95, 0.95);
	vtkAdaptor.drawAxes();
	for (int i = 0; i < c.layers.size(); i++) {
		for (const Segment& segment : c.layers[i].segments) {
			vtkAdaptor.drawSegment(segment)->GetProperty()->SetColor(1, 0, 0);
		}
	}
	vtkAdaptor.display();
}