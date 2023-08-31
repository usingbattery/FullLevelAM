#include "File.h"
#include "Point3D.h"
#include "StlModel.h"
#include "Cutter.h"
#include "VtkAdaptor.h"
#include "GeomAlgo.h"
#include "LinkSegs.h"

using namespace nsp;

int main() {

	StlModel s("236.STL");
	std::vector<double> heights /*= {0,100,200}*/;
	for (double h = s.bound[2] + 1; h < s.bound[5]; h += 10) {
		heights.push_back(h);
	}
	Cutter c(&s, heights);

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
	int r = 1;
	int g = 0;
	int b = 0;
	int t;
	for (int i = 0; i < c.layers.size(); i++) {
		for (const Polyline& polyline : c.layers[i].contours) {
			vtkAdaptor.drawPolyline(polyline)->GetProperty()->SetColor(r, g, b);
			//t = b;
			//b = g;
			//g = r;
			//r = t;
		}
	}
	vtkAdaptor.display();

	//Layer clone = c.layers[1].clone();

	//VtkAdaptor vtkAdaptor1;
	//vtkAdaptor1.setBackgroundColor(0.95, 0.95, 0.95);
	//vtkAdaptor1.drawAxes();
	//for (int i = 0; i < c.layers.size(); i++) {
	//	for (const Segment& segment : c.layers[i].segments) {
	//		vtkAdaptor1.drawSegment(segment)->GetProperty()->SetColor(1, 0, 0);
	//	}
	//}
	//vtkAdaptor1.display();
}