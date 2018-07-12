计算p(x)=3*x^6+7*x^5-3*x^4+2*x^3+7*x^2-7*x-15的值
#include"stdio.h"
//polynomialld
double f(double a[],int n,double x)
{
	int i;
	double result=a[n-1];
	for(i=n-2;i>=0;i--)
		result=result*x+a[i];
	return result;
}
//main
void main()
{
	int i;
	static double a[7]={-15.0,-7.0,7.0,2.0,-3.0,7.0,3.0};
	static double x[6]={-2.0,-0.5,1.0,2.0,3.7,4.0};
	double result;
	for(i=0;i<6;i++)
	{result=f(a,7,x[i]);
	printf("x=5.2lf,p(x)=%7.4e\n",x[i],result);}     
}