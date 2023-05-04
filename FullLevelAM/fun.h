//
// Created by MBP on 2023/4/18.
//

#ifndef GCODE_FUN_H
#define GCODE_FUN_H

#include "Polyline.h"
#include "Triangle.h"
#include "Plane.h"
#include "Segment.h"
#include "GeomAlgo.h"
#include "Layer.h"
namespace nsp {
	//Save polygons to a text file
	void writePolyline(std::string path, Polyline polyline, bool clear_txt = true);

	//Reading Polygons from a Text File
	Polyline readPolyline(std::string path);
	//Intersection of Space Triangle and Plane
	Segment intersectTrianglePlane(Triangle triangle, Plane plane);

#endif //GCODE_FUN_H
}