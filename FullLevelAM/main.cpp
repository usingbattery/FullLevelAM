#include "File.h"
#include "Point3D.h"
#include "StlModel.h"
#include "Layers.h"
#include "VtkAdaptor.h"
#include "fun.h"
#include "GeomAlgo.h"
using namespace nsp;

// 
//
int main() {

	//std::vector<Segment> segmentsTem;
	//segmentsTem = intersectTrianglePlane(Triangle(Point3D(1, 0, 0), Point3D(0, 1, 0), Point3D(-1, 0, 0), Vector3D(0, 0, 1)), Plane(Point3D(0, 0, 0), Vector3D(0, 0, 1)));
	//std::cout << segmentsTem.size() << std::endl;
	//for (Segment segment : segmentsTem) {
	//	std::cout << "\t" << segment.toString() << std::endl;
	//}
	//exit(0);

	//Plane plane(Point3D(1, 0, 0), Vector3D(1, 0, 0));
	//Segment seg(Point3D(1, 0, 0), Point3D(0, 1, 0));
	//auto p = intersectSegmentPlane(seg, plane);
	//Point3D p1(1, 0, 0);
	//std::cout << p1.toString() << std::endl;
	//if (p != nullptr) std::cout << p->toString() << std::endl;
	//else std::cout << "suc" << std::endl;

	//Triangle tri(Point3D(1, 0, 0), Point3D(-1, 0, 0), Point3D(0, 1, 0));
	//Segment sem = intersectTrianglePlane(tri, plane);
	//std::cout << sem.toString() << std::endl;

	//VtkAdaptor vtkAdaptor;
	//vtkAdaptor.setBackgroundColor(0.95, 0.95, 0.95);
	//vtkAdaptor.drawAxes();
	//vtkAdaptor.drawStlModel("236.STL");
	//
	//vtkAdaptor.drawPoint(Point3D(0, 0, -30))->GetProperty()->SetColor(1,0,0);
	//vtkAdaptor.display();
	//vtkAdaptor.drawPoint(Point3D(50, 50, 50))->GetProperty()->SetColor(1, 0, 0);
	//Polyline polyline;
	//polyline.addPoint(Point3D(1, 1, 1));
	//polyline.addPoint(Point3D(50, 2, 10));
	//polyline.addPoint(Point3D(20, 10, 30));
	//polyline.addPoint(Point3D(50, 80, 50));
	//auto tp = vtkAdaptor.drawPolyline(polyline);
	//tp->GetProperty()->SetColor(0.1, 0.7, 0.7);
	//tp->GetProperty()->SetLineWidth(2);

	//vtkAdaptor.display();

	StlModel s("236.STL");
	//std::multimap<double, Triangle>::iterator it = s.triangles.begin();
	//int i = 0;
	//while (it != s.triangles.end())
	//{
	//	std::cout << it->first << "\t" << it->second.toString() << std::endl;
	//	it++;
	//	i++;
	//}
	//std::cout << i;
	Layers ls(s);
	for (int i = 0; i < ls.layersNum; i++) {
		std::cout << ls.layers[i].plane.P.z << std::endl;
		for (Segment segment : ls.layers[i].segments) {
			std::cout<<"\t"<<segment.toString() << std::endl;
		}
	}

	//    Point3D p = Point3D(1, 2, 3, 4);
	//    std::cout << p.toString();

	//    std::string filePathIOS = "~/Desktop/CLion/FullLevelAM/FullLevelAM/GCode.txt";
	//    std::string filePathWin = "GCode.txt";
	//    openFile(filePathWin);
	//    G00(1, 1, 1, 100);
	//    G01(1, 2, 3, 100);
	//    G00(1, 1, doubleNull, 100);
	//    G02(17, 1, 2, 3, 5, 1000);
	//    closeFile();
}

//#include <vtkActor.h>
//#include <vtkAreaPicker.h>
//#include <vtkDataSetMapper.h>
//#include <vtkDataSetSurfaceFilter.h>
//#include <vtkExtractGeometry.h>
//#include <vtkIdFilter.h>
//#include <vtkIdTypeArray.h>
//#include <vtkInteractorStyleRubberBandPick.h>
//#include <vtkNamedColors.h>
//#include <vtkNew.h>
//#include <vtkObjectFactory.h>
//#include <vtkPlanes.h>
//#include <vtkPointData.h>
//#include <vtkPointSource.h>
//#include <vtkPolyData.h>
//#include <vtkPolyDataMapper.h>
//#include <vtkProperty.h>
//#include <vtkRenderWindow.h>
//#include <vtkRenderWindowInteractor.h>
//#include <vtkRenderer.h>
//#include <vtkRendererCollection.h>
//#include <vtkSmartPointer.h>
//#include <vtkUnstructuredGrid.h>
//#include <vtkVersion.h>
//#include <vtkVertexGlyphFilter.h>
//#include<vtkPropPicker.h>
//#if VTK_VERSION_NUMBER >= 89000000000ULL
//#define VTK890 1
//#endif
//
//#include <vtkAutoInit.h>
//VTK_MODULE_INIT(vtkRenderingOpenGL2);
//VTK_MODULE_INIT(vtkInteractionStyle);
//
//namespace {
//    // Define interaction style
//    class InteractorStyle : public vtkInteractorStyleRubberBandPick
//    {
//    public:
//        static InteractorStyle* New();
//        vtkTypeMacro(InteractorStyle, vtkInteractorStyleRubberBandPick);
//
//        InteractorStyle()
//        {
//            this->SelectedMapper = vtkSmartPointer<vtkDataSetMapper>::New();
//            this->SelectedActor = vtkSmartPointer<vtkActor>::New();
//            this->SelectedActor->SetMapper(SelectedMapper);
//        }
//
//        virtual void OnLeftButtonUp() override
//        {
//            vtkNew<vtkNamedColors> colors;
//
//
//            // Forward events
//            vtkInteractorStyleRubberBandPick::OnLeftButtonUp();
//
//            //获取鼠标框选矩形 frustum  
//            vtkPlanes* frustum = static_cast<vtkAreaPicker*>(this->GetInteractor()->GetPicker())->GetFrustum();
//
//            vtkNew<vtkExtractGeometry> extractGeometry;
//            extractGeometry->SetImplicitFunction(frustum);
//            extractGeometry->SetInputData(this->Points);
//            extractGeometry->Update();
//
//
//            vtkNew<vtkVertexGlyphFilter> glyphFilter;
//            glyphFilter->SetInputConnection(extractGeometry->GetOutputPort());
//            glyphFilter->Update();
//
//
//            vtkPolyData* selected = glyphFilter->GetOutput();
//            std::cout << "Selected " << selected->GetNumberOfPoints() << " points."
//                << std::endl;
//            std::cout << "Selected " << selected->GetNumberOfCells() << " cells."
//                << std::endl;
//
//            vtkIdTypeArray* ids = dynamic_cast<vtkIdTypeArray*>(selected->GetPointData()->GetArray("OriginalIds"));
//            for (vtkIdType i = 0; i < ids->GetNumberOfTuples(); i++)
//            {
//                std::cout << "Id " << i << " : " << ids->GetValue(i) << std::endl;
//
//            }
//
//            this->SelectedMapper->SetInputData(selected);
//            this->SelectedMapper->ScalarVisibilityOff();
//
//            this->SelectedActor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());
//            this->SelectedActor->GetProperty()->SetPointSize(5);
//
//            this->CurrentRenderer->AddActor(SelectedActor);
//            this->GetInteractor()->GetRenderWindow()->Render();
//            this->HighlightProp(NULL);
//        }
//
//
//        void SetPoints(vtkSmartPointer<vtkPolyData> points)
//        {
//            this->Points = points;
//        }
//
//
//    private:
//        vtkSmartPointer<vtkPolyData> Points;
//        vtkSmartPointer<vtkActor> SelectedActor;
//        vtkSmartPointer<vtkDataSetMapper> SelectedMapper;
//    };
//
//
//    vtkStandardNewMacro(InteractorStyle);
//} // namespace
//
//int main(int, char* [])
//{
//    vtkNew<vtkNamedColors> colors;
//
//
//    vtkNew<vtkPointSource> pointSource;
//    pointSource->SetNumberOfPoints(20);
//    pointSource->Update();
//
//
//    vtkNew<vtkIdFilter> idFilter;
//    idFilter->SetInputConnection(pointSource->GetOutputPort());
//#if VTK890
//    idFilter->SetCellIdsArrayName("OriginalIds");
//    idFilter->SetPointIdsArrayName("OriginalIds");
//#else
//    idFilter->SetIdsArrayName("OriginalIds");
//#endif
//    idFilter->Update();
//
//
//    vtkNew<vtkDataSetSurfaceFilter> surfaceFilter;
//    surfaceFilter->SetInputConnection(idFilter->GetOutputPort());
//    surfaceFilter->Update();
//
//    vtkPolyData* input = surfaceFilter->GetOutput();
//
//
//    // Create a mapper and actor
//    vtkNew<vtkPolyDataMapper> mapper;
//    mapper->SetInputData(input);
//    mapper->ScalarVisibilityOff();
//
//
//    vtkNew<vtkActor> actor;
//    actor->SetMapper(mapper);
//    actor->GetProperty()->SetPointSize(3);
//    actor->GetProperty()->SetColor(colors->GetColor3d("Gold").GetData());
//
//
//    // Visualize
//    vtkNew<vtkRenderer> renderer;
//    vtkNew<vtkRenderWindow> renderWindow;
//    renderWindow->AddRenderer(renderer);
//    renderWindow->SetWindowName("HighlightSelectedPoints");
//
//
//    vtkNew<vtkAreaPicker> areaPicker;
//    vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
//    renderWindowInteractor->SetPicker(areaPicker);
//    renderWindowInteractor->SetRenderWindow(renderWindow);
//
//
//    renderer->AddActor(actor);
//    renderer->SetBackground(colors->GetColor3d("DarkSlateGray").GetData());
//
//
//    renderWindow->Render();
//
//
//    vtkNew<InteractorStyle> style;
//    style->SetPoints(input);
//    //style->StartSelect();//开始选取
//    renderWindowInteractor->SetInteractorStyle(style);
//
//
//    renderWindowInteractor->Start();
//
//    return EXIT_SUCCESS;
//}