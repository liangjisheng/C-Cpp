#include"stdio.h"
#include"math.h"
#define eps 1e-8
//求函数值
double f(double x)
{return x*x-x+1;}
//求定积分
double integral(double a,double b)
{
	int n=1,i;
	double h,dint0,dint1;
	dint1=(f(a)+f(b))*(b-a)/2;
	do{
		n=n*2;h=(b-a)/n;dint0=dint1;
		dint1=f(a)+f(b);
		for(i=1;i<n;i++)
			dint1=dint1+2*f(a+i*h);
		dint1=dint1*h/2;
	}while(fabs(dint0-dint1)>eps);
	return dint1;
}
//主程序
void main()
{
	double a,b;
	printf("Please input a b:");
	scanf("%lf%lf",&a,&b);
	printf("from a to b is:%.8f\n",integral(a,b));
}