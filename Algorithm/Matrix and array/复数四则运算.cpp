#include"stdio.h"
//plus
void cplus(double a,double b,double c,double d,double *e,double *f)
{*e=a+c;*f=b+d;}
//minus
void cminus(double a,double b,double c,double d,double *e,double *f)
{*e=a-c;*f=b-d;}
//mul
void cmul(double a,double b,double c,double d,double *e,double *f)
{*e=a*c-b*d;*f=a*d+b*c;}
//div
void cdiv(double a,double b,double c,double d,double *e,double *f)
{
	double sq=c*c+d*d;
	*e=(a*c+b*d)/sq;
	*f=(b*c-a*d)/sq;
}
//main
void main()
{
	double a,b,c,d,e,f;
	printf("input a and b:");
	scanf("%lf%lf",&a,&b);
	printf("input c and d:");
	scanf("%lf%lf",&c,&d);
	cplus(a,b,c,d,&e,&f);
	printf("(%f+%fi)+(%f+%fi)=%f+%fi\n",a,b,c,d,e,f);
	cminus(a,b,c,d,&e,&f);
	printf("(%f+%fi)-(%f+%fi)=%f+%fi\n",a,b,c,d,e,f);
	cmul(a,b,c,d,&e,&f);
	printf("(%f+%fi)*(%f+%fi)=%f+%fi\n",a,b,c,d,e,f);
	cdiv(a,b,c,d,&e,&f);
	printf("(%f+%fi)/(%f+%fi)=%f+%fi\n",a,b,c,d,e,f);
}