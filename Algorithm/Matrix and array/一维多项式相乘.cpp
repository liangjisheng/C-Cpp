计算a(x)=2*x^5+3*x^4-x^3+2*x^2+5*x-4与b(x)=3*x^3+x^2-2*x-3的乘积，得到乘积各项的系数
#include"stdio.h"
//polynomial_mul
void f(double a[],int m,double b[],int n,double r[],int k)
{
	int i,j;
	for(i=0;i<k;i++)
		r[i]=0.0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			r[i+j]+=a[i]*b[j];
	}
}
//main
void main()
{
	int i;
	static double a[6]={-4.0,5.0,2.0,-1.0,3.0,2.0};
	static double b[4]={-3.0,-2.0,1.0,3.0};
	double r[9];
	f(a,6,b,4,r,9);
	printf("多项式a与b的乘积的各项系数如下:\n");
	for(i=0;i<9;i++)
		printf("r(%d)=%8.4e\n",i,r[i]);
}