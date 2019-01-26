#include"stdio.h"
#include"stdlib.h"
#include"math.h"
//func
double func(double x)
{return x*exp(-x*x);}
//jifen
double jifen(double x1,double x2,double eps)
{
	int i,n=1;
	double fx1,fx2,h,t1,p,s,x,result;
	fx1=func(x1);
	fx2=func(x2);
	h=x2-x1;
	t1=h*(fx1+fx2)/2.0;
	p=eps+1.0;
	while(p>=eps){
		s=0.0;
		for(i=0;i<n;i++)
		{x=x1+i*h+0.5*h;s+=func(x);}
		result=(t1+h*s)/2.0;
		n=2*n;
		t1=result;
		h=h/2.0;
		p=fabs(t1-result);
	}
	return result;
}
//main
void main()
{
	char again;
	double x1,x2,eps,t;
	printf("求定积分算法.\n");
s1:
	printf("输入定积分区间:");
	fflush(stdin);
	scanf("%lf%lf",&x1,&x2);
	printf("输入精度:");
	fflush(stdin);
	scanf("%lf",&eps);
	t=jifen(x1,x2,eps);
	printf("the result is:%e\n",t);
s2:
	printf("\n继续执行(y/n)?");
	fflush(stdin);
	scanf("%c",&again);
	if(again=='n'||again=='N')goto s3;
	else if(again=='y'||again=='Y')goto s1;
	else {printf("输入错误,重新输入.\n");goto s2;}
s3:
	printf("结束\n");
}