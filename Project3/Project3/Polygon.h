// By: Taha Khan
// Date:9/23/2017
#ifndef Polygon_H_INCLUDED
#define Polygon_H_INCLUDED

#include "Point.h"
//------------------ Data Type Polygon-----------------//
const unsigned MaxSides = 10;
const unsigned MinSides = 3;

struct Polygon {
	unsigned numSides;  //No of sides in Polygon
	Point v[MaxSides];  // Lists the coordinates of Polygon
};

//--------------Data Type Polygon Functions---------------//
void ShowPoly(Polygon &p);
double PolyCircumference(Polygon &thePoly);
double AreaOfTriangle(Point pt1, Point pt2, Point pt3);
void PolyArea(Polygon &thePoly, double *area);

#endif
