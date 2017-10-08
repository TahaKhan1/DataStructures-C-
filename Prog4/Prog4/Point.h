/*=============== P o i n t . h ===============

Starter Code by:  George Cheney
ECE Dept.
UMASS Lowell

Finished Code by: Taha Khan

PURPOSE
Provides the definition of data type Point and function prototypes
of data type Point functions

CHANGES
09-20-2016 gpc  -   Distribute to EECE322 class.
Modified: 10/7/2017
*/
#ifndef POINT_H
#define POINT_H

// --------------- H e a d e r   F i l e s-----------------------
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

// --------------- D a t a    T y p e    P o i n t ---------------
class Point
{
public:
	// Constructors
	Point();
	Point(double xVal, double yVal): x(xVal), y(yVal){} // Explicit constructor
	// Accessors
	double X() const;
	double Y() const;
	// Mutator: Set the x and y coordinator of a Point
	void Set(double xVal, double yVal);
	
	// Return the length of line from the calling Point to Point pt2
	double Length(Point pt2);
	// Input - Output functions
	bool Get();
	void Show() const;
	// Function to find the area of a triangle
	double AreaOfTriangle(Point pt1, Point pt2, Point pt3);


private:
	double x;    // -- x coordinate of a point
	double y;    // -- y coordinate of a point
};
#endif
