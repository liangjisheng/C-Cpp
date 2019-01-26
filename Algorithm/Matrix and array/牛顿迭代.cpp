#include"stdio.h"
#include"math.h"
//func
double func(double x)
{return x*x*x*x-3*x*x*x+1.5*x*x-4.0;}
//dfunc
double dfunc(double x)
{return 4*x*x*x-9*x*x+3*x;}
//newton
int newton(double *x,int maxcyc,double precision)
{
	double x0=*x,x1;
	int i=0;
	while(i<maxcyc){
		if(dfunc(x0)==0.0)
		{printf("迭代过程中导数为0.\n");return 0;}
		x1=x0-func(x0)/dfunc(x0);
		if(fabs(x1-x0)<precision||fabs(func(x1))<precision)
		{*x=x1;return 1;}
		else x0=x1;
		i++;
	}
	printf("迭代次数超过预设值,仍没有达到精度.\n");
	return 0;
}
//main
void main()
{
	double x=2.0,precision=1e-5;
	int maxcyc=1000,result;
	result=newton(&x,maxcyc,precision);
	if(result)printf("方程在2.0附近有根.\nx=%.4lf\n",x);
	else printf("迭代失败\n");
}