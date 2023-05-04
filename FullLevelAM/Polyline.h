//
// Created by MBP on 2023/4/18.
//

#ifndef GCODE_POLYLINE_H
#define GCODE_POLYLINE_H

#include "Segment.h"
namespace nsp {

    class Polyline {

    public:

        std::vector<Point3D> points;

        Polyline() {}

        std::string toString();

        //Clone a multi line segment
        Polyline clone();

        //Obtain the number of midpoints in multiple line segments
        int count();

        //Add a point at the end of a multiple line segment
        void addPoint(Point3D pt);

        //Add a point before the starting point of multiple line segments
        void raddPoint(Point3D pt);

        //Remove a point based on its sequence number
        void removePoint(int index);

        //Obtain a point based on its serial number
        Point3D point(int index);

        //Get starting point
        Point3D startPoint();

        //Get endpoint
        Point3D endPoint();

        //Determine whether multiple line segments are closed
        bool isClosed();

        //Reverse the point order of a polyline
        void reverse();

        //Obtain polygon area
        double getArea();

        //Adjust the polygons on the XY plane to counterclockwise direction
        void makeCCW();

        //Adjust the polygons on the XY plane to a clockwise direction
        void makeCW();

        //Determine if the polygon is counterclockwise
        bool isCCW();

        //Translate multiple line segments based on a vector
        void translate(Vector3D vec);

        //Add a line segment at the beginning or end of a multiple line segment
        bool appendSegment(Segment seg);

    private:

    };

}
#endif //GCODE_POLYLINE_H
