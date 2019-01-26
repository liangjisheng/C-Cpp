#ifndef POINT_H
#define POINT_H

#ifdef DLL_FILE
class _declspec(dllexport) point
#else
class _declspec(dllimport) point
#endif
{
public:
	double x,y;
	point();
	point(double _x,double _y);
};

#endif