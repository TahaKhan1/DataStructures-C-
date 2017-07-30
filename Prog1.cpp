/*=============== P r o g 1 . c p p ===============

Starter Code by:  George Cheney
ECE Dept.
UMASS Lowell

Finshed Code by:  Your Name Here

PURPOSE
Read in the definition of an arbitrary convex polygon, and then
compute both the circumerence and the area of the polygon.

CHANGES
09-02-2016 gpc  -   Distribute to EECE322 class.
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

// --------------- D a t a    T y p e    P o i n t ---------------
// . . . Define Data Type Point Here . . .
struct Point {
	double x;
	double y;
};

//----- D a t a    T y p e    P o i n t    F u n c t i o n s -----

// . . . Define Functions for Data Type Point Here . . .
double Length(Point pt1, Point pt2) {

	double a = sqrt((pt1.x - pt2.x)*(pt1.x - pt2.x) + (pt1.y - pt2.y)*(pt1.y - pt2.y));
	return a;
}
bool GetPoint(Point &pt) {
	cin >> pt.x >> pt.y;
	if (pt.x<0) {
		return false;
	}
}
void ShowPoint(Point pt) {
	cout << "(" << pt.x << "," << pt.y << ")" << endl;
}

// --------------- D a t a    T y p e    P o l y g o n ---------------

// . . . Define Data Type Polygon Here . . .
const unsigned MaxSides = 10;
const unsigned MinSides = 3;
struct Polygon
{
	unsigned numSides;
	Point v[MaxSides];
};

//----- D a t a    T y p e    P o l y g o n    F u n c t i o n s -----

// . . . Define Data Type Polygon Functions Here . . .
double PolyCircumference(Polygon &thePoly) {
	double b = 0;
	int i;
	for (i = 0; i<5; i++) {
		b = b + Length(thePoly.v[i], thePoly.v[i + 1]);
	}
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
	for (int i = 0; i<(thePoly.numSides - 2); i++) {
		area[0] = 0;
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

//--------------- m a i n ( ) ---------------

int main()
{
	Polygon poly;   // The polygon definition

					// Start out with zero polygon sides.
	poly.numSides = 0;

	// Read in a polygon definition. If a valid polygon was entered,
	// display its circumference and area; otherwise display an
	// error message and terminate execution.
	cout << "ENTER A POLYGON DEFINITION: " << endl << endl;

	for (;;)
	{
		// Read in the next point
		cout << "\nEnter next point: ";
		if (!GetPoint(poly.v[poly.numSides]))
			break;

		// Update the ploygon size.
		++poly.numSides;

		// If the polygon is full, say so and stop taking input.
		if (poly.numSides >= MaxSides)
		{
			cout << "\nPolynomial Full" << endl;
			break;
		}
	}

	// Make sure that the polygon is valid.
	if (poly.numSides < MinSides)
	{
		cout << "***ERROR: A polygon must have at least 3 sides" << endl;
		return 0;
	}

	// The definition is valid, show the definition.
	cout << endl << "Here is the polygon definition:" << endl;
	ShowPoly(poly);

	// Compute and display the circumference.
	cout << "\nCircumference = " << PolyCircumference(poly) << endl;

	// Compute and display the areas of the polygon and its embedded triangles.

	// area[0] gives the area of the entire polygon.
	// area[i] (i > 0) gives the area of the i'th embedded triangle.
	double area[MaxSides + 1];

	PolyArea(poly, area);

	cout << "\nPolygon Area = " << area[0] << endl << endl;

	const unsigned numTriangles = poly.numSides - 2;   // Number of embedded triangles

	for (unsigned i = 1; i <= numTriangles; ++i)
		cout << "Triangle " << i << ": Area = " << area[i] << endl;

	cout << endl;

	return 0;
}
