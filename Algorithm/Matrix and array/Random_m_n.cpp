产生m到n之间的随机小数
#include"stdio.h"
//rand01
double rand01(double *r)
{
	double base,v,u,t1,t2,t3;
	base=256.0;u=17.0;v=159.0;
	t1=u*(*r)+v;
	t2=(int)(t1/base);
	t3=t1-t2*base;
	*r=t3;
	return t3/base;
}
//main
void main()
{
	int i;
	double r=4.0,m,n;
	printf("create 10 number from m to n:\n");
	printf("input the m and n:");
	scanf("%lf%lf",&m,&n);
	for(i=0;i<10;i++)
		printf("%10.7f\n",m+(n-m)*rand01(&r));
}




产生m到n之间的随机整数
#include"stdio.h"
//rand01
double rand01(double *r)
{
	double base,v,u,t1,t2,t3;
	base=256.0;u=17.0;v=159.0;
	t1=u*(*r)+v;
	t2=(int)(t1/base);
	t3=t1-t2*base;
	*r=t3;
	return t3/base;
}
//main
void main()
{
	int i,m,n;
	double r=4.0;
	printf("create 10 number from m to n:\n");
	printf("input the m and n:");
	scanf("%d%d",&m,&n);
	for(i=0;i<10;i++)
		printf("%d",m+(int)((n-m)*rand01(&r)));
        printf("\n");
}