/*---//-------- Polygon.cpp------//
//----------By:Taha Khan--- //
//------ Date:Sept 23 2017----//--- */

#include <iostream>
#include "Polygon.h"
#include <cmath>

//----- D a t a    T y p e    P o l y g o n    F u n c t i o n s -----

// . . . Define Data Type Polygon Functions Here . . .
//-------------------PolyCircumference-----------------------//
double PolyCircumference(Polygon &thePoly) {
	double circ = 0;
	for (unsigned i = 0; i < thePoly.numSides; i++)
	{
		Point pt1 = thePoly.v[i];
		Point pt2 = thePoly.v[(i + 1) % thePoly.numSides];

		circ = circ + pt1.Length(pt2);
	}
	return circ;
}
double AreaOfTriangle(Point pt1, Point pt2, Point pt3){
	double a = pt1.Length(pt2);
	double b = pt1.Length(pt3);
	double c = pt2.Length(pt3);
	double s = (a + b + c) / 2;
	double area= sqrt(s*(s - a)*(s - b)*(s - c));
	return area;
}
void PolyArea(Polygon &thePoly, double *area) {
	area[0] = 0;
	for (unsigned i = 0; i < (thePoly.numSides - 2); i++) {
		area[i + 1] = AreaOfTriangle(thePoly.v[0], thePoly.v[i + 1], thePoly.v[i + 2]);
		area[0] = area[0] + area[i + 1];
	}
}
void ShowPoly(Polygon &p)
{
	for (unsigned i = 0; i < p.numSides; i++)
	     (p.v[i].Show());
}