// Provided Code
// Written code
#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
using namespace std;
class Point {
	public:
		Point();    // Default Constructor
		Point(double xVal, double yVal);  // Explicit Constructor

  // Accessor Functions
		double X() const;
		double Y() const;

  // Mutator:Set the x and y coordinates of a point
		void Set(double xVal, double yVal);
 //  Return the length of a line from calling Point to Point pt2
		double Length(Point pt2);

 // Input-Output Functions
		bool Get(istream &is=cin);    // Input the Point from the stream &is
		void Show(ostream &os=cout) const;  // Output a point to the stream "os";

private:
	double x;    // x coordinate of the point
	double y;    // y coordinate of the point 

};
#endif
