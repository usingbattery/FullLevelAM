#pragma once

#include"Point3D.h"
#include"Segment.h"
#include"Polyline.h"
#include<vtkInteractorStyleTrackballCamera.h>
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkAxesActor.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkSTLReader.h>
#include <vtkSphereSource.h>
#include <vtkLineSource.h>
#include <vtkPoints.h>
#include <vtkNew.h>
#include<vtkProperty.h>

class VtkAdaptor {
public:
	vtkNew<vtkRenderer> renderer;
	vtkNew<vtkRenderWindow> window;
	vtkNew<vtkRenderWindowInteractor> interactor;

	VtkAdaptor(double r = 0.95, double g = 0.95, double b = 0.95);
	void display();
	void setBackgroundColor(double r, double g, double b);
	vtkNew<vtkAxesActor> drawAxes(double length = 100.0, int shaftType = 0, double cylinderRadius = 0.01, double coneRadius = 0.2);
	//vtkNew<vtkActor> drawActor(vtkNew<vtkActor>& actor);

	/*template<typename T>
	vtkNew<vtkActor>& drawPdSrc(T& Pdsrc);*/
	

	vtkNew<vtkActor> drawStlModel(const char* stlFilePath);
	

	void removeActor(vtkNew<vtkActor>& actor);
		

	vtkNew<vtkActor> drawPoint(nsp::Point3D point, double radius = 2.0);
		
	

	vtkNew<vtkActor> drawSegment(nsp::Segment seg);
		

	vtkNew<vtkActor> drawPolyline(nsp::Polyline polyline);
	
};
