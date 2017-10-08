// Point.cpp//
// By: Taha Khan
// Data 09/23/2017
// Definition:  Get Point & Show Point
#include<iostream>
#include "Point.h"
#include <cmath>
#include "limits.h"

using namespace std;
//-------------------------Default Constructor-----------------//
Point::Point()
{
	x = 0;
	y = 0;
}

//----------------Point::Set()---------------------//

void Point::Set(double xVal, double yVal)
{
	double x=xVal;
	double y=yVal;
}

//----------------Point::Length()-------------------//

double Point::Length(Point pt2)
{
	double dx = (pt2.x-X());
	double dy = (pt2.y-Y());
	return sqrt(dx*dx + dy*dy);
}

// ---------------Point::Get()---------------------//

bool Point::Get(istream &is)
{
	bool gotPoint = false;
	if (is.peek() != '\n')
	{
		is >> x >> y;
		gotPoint = true;
	}
		is.ignore(INT_MAX, '\n');
		return gotPoint;
	}
//-------------------Point::Show()------------------//
void Point::Show(ostream &os) const
{
       os<< "(" << X() << ","<< Y() << ")" << endl;
}
//-----------------double X()------------------------//
double Point::X() const
{
	return x;
};
//-----------------double Y()------------------------//
double Point::Y() const
{
	return y;
};