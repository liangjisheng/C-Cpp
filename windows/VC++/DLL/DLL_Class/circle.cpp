#ifndef DLL_FILE
#define DLL_FILE
#endif

#include"circle.h"

circle::circle() {
	center=point(0,0);
	radius=0;
}

double circle::GetArea()
{ return 3.1415*radius*radius; }

double circle::GetGrith()
{ return 2*3.1415*radius; }

void circle::SetCenter(const point& re)
{ center=re; }

void circle::SetRadius(double r)
{ radius=r; }