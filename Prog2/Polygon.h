/*---//-------- Polygon.h------//
//----------By:Taha Khan--- //
//------ Date:July 31 2017----//--- */
#include "Point.h"
#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED
// --------------- D a t a    T y p e    P o l y g o n ---------------
// . . . Define Data Type Polygon Here . . .
const unsigned MaxSides = 10;
const unsigned MinSides = 3;
struct Polygon
{
	unsigned numSides;
	Point v[MaxSides];
};
double PolyCircumference(Polygon &thePoly);
double TriangleArea(Point pt0, Point pt1, Point pt2);
void PolyArea(Polygon &thePoly, double *area);
void ShowPoly(Polygon &p);
#endif
