#include "VtkAdaptor.h"
#include "vtkTriangleStrip.h"


VtkAdaptor::VtkAdaptor(double r, double g, double b) {
	renderer->SetBackground(r, g, b);
	window->AddRenderer(renderer);
	window->SetSize(1000, 1000);
	interactor->SetRenderWindow(window);
	vtkSmartPointer<vtkInteractorStyleTrackballCamera> style =
		vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
	interactor->SetInteractorStyle(style);
	interactor->Initialize();
}

void VtkAdaptor::display() {
	interactor->Start();
}

void VtkAdaptor::setBackgroundColor(double r, double g, double b) {
	renderer->SetBackground(r, g, b);
}

vtkNew<vtkAxesActor> VtkAdaptor::drawAxes(double length, int shaftType, double cylinderRadius, double coneRadius) {
	vtkNew<vtkAxesActor> axes;
	axes->SetTotalLength(length, length, length);
	axes->SetShaftType(shaftType);
	axes->SetCylinderRadius(cylinderRadius);
	axes->SetConeRadius(coneRadius);
	axes->SetAxisLabels(0);
	renderer->AddActor(axes);
	return axes;
}

//vtkNew<vtkActor>& VtkAdaptor::drawActor(vtkNew<vtkActor>& actor) {
//	renderer->AddActor(actor);
//	return actor;
//}

//template<typename T>
//vtkNew<vtkActor>& VtkAdaptor::drawPdSrc( T& PdSrc) {
//	vtkNew<vtkPolyDataMapper> mapper;
//	mapper->SetInputConnection(PdSrc->GetOutputPort());
//	vtkNew<vtkActor> actor;
//	actor->SetMapper(mapper);
//	return drawActor(actor);

vtkNew<vtkActor> VtkAdaptor::drawStlModel(const char* stlFilePath) {
	vtkNew<vtkSTLReader> reader;
	reader->SetFileName(stlFilePath);
	vtkNew<vtkPolyDataMapper> mapper;
	mapper->SetInputConnection(reader->GetOutputPort());
	vtkNew<vtkActor> actor;
	actor->SetMapper(mapper);
	renderer->AddActor(actor);
	return actor;
}

void VtkAdaptor::removeActor(vtkNew<vtkActor>& actor) {
	renderer->RemoveActor(actor);
}

vtkNew<vtkActor> VtkAdaptor::drawPoint(nsp::Point3D point, double radius) {
	vtkNew<vtkSphereSource> src;
	src->SetCenter(point.x, point.y, point.z);
	src->SetRadius(radius);

	vtkNew<vtkPolyDataMapper> mapper;
	mapper->SetInputConnection(src->GetOutputPort());
	vtkNew<vtkActor> actor;
	actor->SetMapper(mapper);
	renderer->AddActor(actor);
	return actor;
}

vtkNew<vtkActor> VtkAdaptor::drawSegment(nsp::Segment seg) {
	vtkNew<vtkLineSource> src;
	src->SetPoint1(seg.A.x, seg.A.y, seg.A.z);
	src->SetPoint2(seg.B.x, seg.B.y, seg.B.z);
	vtkNew<vtkPolyDataMapper> mapper;
	mapper->SetInputConnection(src->GetOutputPort());
	vtkNew<vtkActor> actor;
	actor->SetMapper(mapper);
	renderer->AddActor(actor);
	return actor;
}

vtkNew<vtkActor> VtkAdaptor::drawPolyline(nsp::Polyline polyline) {
	vtkNew<vtkLineSource> src;
	vtkNew<vtkPoints> points;
	for (int i = 0; i < polyline.count(); i++) {
		auto pt = polyline.point(i);
		points->InsertNextPoint(pt.x, pt.y, pt.z);
	}
	src->SetPoints(points);
	vtkNew<vtkPolyDataMapper> mapper;
	mapper->SetInputConnection(src->GetOutputPort());
	vtkNew<vtkActor> actor;
	actor->SetMapper(mapper);
	renderer->AddActor(actor);
	return actor;
}

vtkNew<vtkActor> VtkAdaptor::drawPrism(nsp::Polyline polyLine, double targetHeight) {
	// geometry structure
	vtkNew<vtkPoints> points;
	double currentHeight = polyLine.points[0].z;
	for (size_t i = 0; i < polyLine.points.size(); i++) {
		double tem0[] = { polyLine.points[i].x,polyLine.points[i].y,currentHeight };
		double tem1[] = { polyLine.points[i].x,polyLine.points[i].y,targetHeight};
		points->InsertPoint(2*i, tem0);
		points->InsertPoint(2*i+1, tem1);
	}
	// topology structure
	vtkNew<vtkCellArray> strips;
	const int pointsNum = 2 * polyLine.points.size();
	strips->InsertNextCell(pointsNum + 2);
	for (int i = 0; i < pointsNum; i++) {
		strips->InsertCellPoint(i);
	}
	strips->InsertCellPoint(0);
	strips->InsertCellPoint(1);
	// environment confige
	vtkNew<vtkPolyData> source;
	source->SetPoints(points);
	source->SetStrips(strips);
	vtkNew<vtkPolyDataMapper> mapper;
	mapper->SetInputData(source);
	vtkNew<vtkActor> actor;
	actor->SetMapper(mapper);
	renderer->AddActor(actor);
	return actor;
}