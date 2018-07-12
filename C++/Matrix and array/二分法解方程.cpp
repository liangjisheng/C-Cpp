#include"stdio.h"
#include"math.h"
//function
double func(double x)
{return 2*x*x*x-5*x-1;}
//erfen
double erfen(double a,double b,double err)
{
	double c=(a+b)/2.0;
	while(fabs(func(c))>err&&func(a-b)>err){
		if(func(c)*func(b)<0)a=c;
		if(func(c)*func(b)>0)b=c;
		c=(a+b)/2.0;
	}
	return c;
}
//main
void main()
{
	double a=1.0,b=2.0,err=1e-3,result;
	printf("二分法解方程:2*x*x*x-5*x-1.\n");
	result=erfen(a,b,err);
	printf("x=%.5lf\n",result);
}