#include"stdio.h"
#include"stdlib.h"
#include"math.h"
//sqrt
double Sqrt(double x,double eps)
{
	double result=x,t=0.0;
	while(fabs(result-t)>eps)t=result,result=0.5*(t+x/t);
	return result;
}
//main
void main()
{
	char again;
	double x,eps,t;
	printf("求解开平方算法.\n");
s1:
	printf("输入一个数字:");
	fflush(stdin);
	scanf("%lf",&x);
	printf("输入精度:");
	fflush(stdin);
	scanf("%lf",&eps);
	t=Sqrt(x,eps);
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
