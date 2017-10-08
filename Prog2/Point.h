/*---//-------- Point.h------//
//----------By:Taha Khan--- //
//------ Date:July 31 2017----//--- */

#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

// --------------- D a t a    T y p e    P o i n t ---------------//
struct Point {
	double x;
	double y;
};

double Length(Point pt1, Point pt2);
bool GetPoint(Point &pt);
void ShowPoint(Point pt);

#endif


