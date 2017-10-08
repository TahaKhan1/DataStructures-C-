/*------------------Point.cpp---------------------------//
//---------------By:Taha Khan------------------//
//--------Date: July 31 2017---------------
//-----Definition of Functions of Point.h---------------- */
#include<iostream>
#include "Point.h"
using namespace std;
//----- D a t a    T y p e    P o i n t    F u n c t i o n s -----

// . . . Define Functions for Data Type Point Here . . .
double Length(Point pt1, Point pt2) {

	double a = sqrt((pt1.x - pt2.x)*(pt1.x - pt2.x) + (pt1.y - pt2.y)*(pt1.y - pt2.y));
	return a;
}
bool GetPoint(Point &pt) {

	if (std::cin.peek() != '\n')
	{
		std::cin >> pt.x >> pt.y;
		std::cin.ignore(INT_MAX, '\n');
		return true;
	}
	return false;

}
void ShowPoint(Point pt) {
	cout << "(" << pt.x << "," << pt.y << ")" << endl;
}