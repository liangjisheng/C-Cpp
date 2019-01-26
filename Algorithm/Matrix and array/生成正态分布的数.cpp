#include"stdio.h"
//rand01
double rand01(double *r)              //0-1之间的随机数
{
	double base,v,u,t1,t2,t3;
	base=256.0;u=17.0;v=159.0;
	t1=u*(*r)+v;
	t2=(int)(t1/base);
	t3=t1-t2*base;
	*r=t3;
	return t3/base;
}
double randzt(double u,double t,double *r)     //正态分布的随机数
{
	int i;
	double total=0.0,result;
	for(i=0;i<12;i++)
		total+=rand01(r);
    result=u+t*(total-6.0);
	return result;
}
//main
void main()
{
	int i;
	double r=5.0,u,t;
	printf("生成10个正态分布的随机数:\n");
	printf("input 均值和方差:");
	scanf("%lf%lf",&u,&t);
	for(i=0;i<10;i++)
		printf("%10.7f\n",randzt(u,t,&r));
}