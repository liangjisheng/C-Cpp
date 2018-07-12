#include"stdio.h"
#include"stdlib.h"
//lagrange
double lagrange(double x[],double y[],int n,double t)
{
	int i,j,k,m;
	double s,result=0.0;
	if(n<1)return result;
	else if(n==1){result=y[0];return result;}
	else if(n==2){result=(y[0]*(t-x[1])-y[1]*(t-x[0]))/(x[0]-x[1]);return result;}
	else{
		i=0;
		while(x[i]<t&&i<n)i++;
		k=i-4;
		if(k<0)k=0;
		m=i+3;
		if(m>n-1)m=n-1;
		for(i=k;i<=m;i++){
			s=1.0;
			for(j=k;j<=m;j++)
			{if(j!=i)s=s*(t-x[j])/(x[i]-x[j]);}
			result=result+s*y[i];
		}
	}
	return result;
}
//main
void main()
{
	double t,z;
	char again;
	static double x[10]={0.10,0.15,0.30,0.40,0.50,0.60,0.70,0.85,0.90,1.00};
	static double y[10]={0.90,0.86,0.78,0.67,0.60,0.55,0.48,0.42,0.38,0.36};
	printf("拉格朗日插值算法演示.\n");
s1:
	printf("input the insert number:");
	fflush(stdin);
	scanf("%lf",&t);
	z=lagrange(x,y,10,t);
	printf("插值点t=%6.3f,计算结果z=%e\n",t,z);
s2:
	printf("\n继续执行(y/n)?");
	fflush(stdin);
	scanf("%c",&again);
	if(again=='y'||again=='Y')goto s1;
	else if(again=='n'||again=='N')goto s3;
	else {printf("输入错误,重新输入.\n");goto s2;}
s3:
	printf("演示结束.\n");
}