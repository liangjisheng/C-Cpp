计算a(x)=2*x^4+4*x^3-3*x^2+6*x-3与b(x)=x^2+x-1的商和余式，即计算a(x)/b(x)=r(x)+L(x),求r(x)和L(x)各项的系数。
#include"stdio.h"
//polynomial_div
void f(double a[],int m,double b[],int n,double r[],int k,double L[],int l)
{
	int i,j,mm,ll;
	for(i=0;i<k;i++)
		r[i]=0.0;
	ll=m-1;
	for(i=k;i>0;i--)
	{
		r[i-1]=a[ll]/b[n-1];
		mm=ll;
		for(j=1;j<=n-1;j++)
		{a[mm-1]-=r[i-1]*b[n-j-1];mm-=1;}
		ll-=1;
	}
	for(i=0;i<1;i++)
		L[i]=a[i];
}
//main
void main()
{
	int i;
	static double a[5]={-3.0,6.0,-3.0,4.0,2.0};
	static double b[3]={-1.0,1.0,1.0};
	double r[3],L[2];
	printf("计算a(x)/b(x)的商多项式和余多项式:\n");
	f(a,5,b,3,r,3,L,2);
	for(i=0;i<=2;i++)
		printf("商多项式系数:r(%d)=%8.4e\n",i,r[i]);
	printf("\n");
	for(i=0;i<=1;i++)
		printf("余多项式系数:L(%d)=%8.4e\n",i,L[i]);
}