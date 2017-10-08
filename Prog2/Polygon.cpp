/*---//-------- Polygon.cpp------//
//----------By:Taha Khan--- //
//------ Date:July 31 2017----//--- */

#include <iostream>
#include "Polygon.h"

//----- D a t a    T y p e    P o l y g o n    F u n c t i o n s -----

// . . . Define Data Type Polygon Functions Here . . .
double PolyCircumference(Polygon &thePoly) {
	double b = 0;
	int i;
	for (i = 0; i<(thePoly.numSides - 1); i++) {
		b = b + Length(thePoly.v[i], thePoly.v[i + 1]);
	}
	b = b + Length(thePoly.v[0], thePoly.v[thePoly.numSides - 1]);
	return b;
}
double TriangleArea(Point pt0, Point pt1, Point pt2) {
	double f, d, e, s;
	f = Length(pt0, pt1);
	d = Length(pt1, pt2);
	e = Length(pt0, pt2);
	s = (f + d + e) / 2;
	double area = sqrt(s*(s - f)*(s - d)*(s - e));
	return area;
}
void PolyArea(Polygon &thePoly, double *area) {
	area[0] = 0;
	for (int i = 0; i<(thePoly.numSides - 2); i++) {
		area[i + 1] = TriangleArea(thePoly.v[0], thePoly.v[i + 1], thePoly.v[i + 2]);
		area[0] = area[0] + area[i + 1];
	}
}
/*--------------- S h o w P o l y ( ) ----------
PURPOSE: Display a polygon.
INPUT PARAMETERS:
p  -- the polygon to be displayed.
*/
void ShowPoly(Polygon &p)
{
	for (unsigned i = 0; i<p.numSides; i++)
		ShowPoint(p.v[i]);
}

