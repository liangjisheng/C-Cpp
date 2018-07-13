#ifdef DLL_FILE
#define DLL_FILE
#endif

#include"point.h"
point::point()
{ x=0.0; y=0.0; }

point::point(double _x,double _y)
{ x=_x; y=_y; }