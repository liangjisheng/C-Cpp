#ifndef CIRCLE_H
#define CIRCLE_H

#include"point.h"

#ifdef DLL_FILE
class _declspec(dllexport) circle
#else
class _declspec(dllimport) circle
#endif
{
	double radius;
	point center;
public:
	void SetCenter(const point& re);
	void SetRadius(double r);
	double GetGrith();
	double GetArea();
	circle();
};
#endif