复数的幂次运算
#include"stdio.h"
//mul
void cmul(double a,double b,double c,double d,double *e,double *f)
{*e=a*c-b*d;*f=a*d+b*c;}
//cpow
void cpow(double a,double b,int n,double *e,double *f)
{
	int i;
	*e=a;*f=b;
	if(n==1)return ;
	else
		for(i=1;i<n;i++)cmul(*e,*f,a,b,e,f);
}
//main
void main()
{
	double a,b,e,f;
	int n;
	printf("input a and b:");
	scanf("%lf%lf",&a,&b);
	printf("input the n:");
	scanf("%d",&n);
	cpow(a,b,n,&e,&f);
	printf("(%f+%fi)的%d次幂=%f+%fi\n",a,b,n,e,f);
}


复数的对数运算
#include"stdio.h"
#include"math.h"
//clog
void clog(double a,double b,double *e,double *f)
{
	double t=log(sqrt(a*a+b*b));
	*e=t;*f=atan2(b,a);
}
//main
void main()
{
	double a,b,e,f;
	printf("input a b:");
	scanf("%lf%lf",&a,&b);
	clog(a,b,&e,&f);
	printf("ln(%f+%fi)=%f+%fi\n",a,b,e,f);
}


复数的正弦运算
#include"stdio.h"
#include"math.h"
//csin
void csin(double a,double b,double *e,double *f)
{
	double p=exp(b),q=1/p;
	*e=sin(a)*(p+q)/2.0;
	*f=cos(a)*(p-q)/2.0;
}
//main
void main()
{
	double a,b,e,f;
	printf("input a,b:");
	scanf("%lf%lf",&a,&b);
	csin(a,b,&e,&f);
	printf("sin(%f+%fi)=%f+%fi\n",a,b,e,f);
}


复数的余弦运算
#include"stdio.h"
#include"math.h"
//ccos
void ccos(double a,double b,double *e,double *f)
{
	double p=exp(b),q=1/p;
	*e=cos(a)*(p+q)/2.0;
	*f=-1.0*sin(a)*(p-q)/2.0;
}
//main
void main()
{
	double a,b,e,f;
	printf("input a,b:");
	scanf("%lf%lf",&a,&b);
	ccos(a,b,&e,&f);
	printf("cos(%f+%fi)=%f+%fi\n",a,b,e,f);
}