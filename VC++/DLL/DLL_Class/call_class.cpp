#include"stdio.h"
#include"..\\circle.h"
#pragma comment(lib,"1225.lib")

int main()
{
	circle c;
	point p(2.0,2.0);
	c.SetCenter(p);
	c.SetRadius(1.0);
	printf("area:%lf,girth:%lf\n",c.GetArea(),c.GetGrith());

	getchar();
	return 0;
}