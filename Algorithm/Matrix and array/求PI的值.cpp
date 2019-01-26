蒙特卡罗算法求PI
#include"stdio.h"
#include"stdlib.h"
#include"time.h"
//monte-carlo
double monte_PI(long n)
{
	long i,sum;
	double PI,x,y;
	srand(time(NULL));
	sum=0;
	for(i=0;i<n;i++)
	{
		x=(double)rand()/RAND_MAX;
		y=(double)rand()/RAND_MAX;
		if(x*x+y*y<=1)sum++;
	}
	PI=4.0*sum/n;
	return PI;
}
//main
void main()
{
	long n;
	double PI;
	printf("蒙特卡罗概率算法计算.\n");
	printf("输入投点数量:");
	scanf("%ld",&n);
	PI=monte_PI(n);
	printf("PI=%f\n",PI);
}


割圆术求PI
#include"stdio.h"
#include"math.h"
//割圆术算法
void cycle(int n)
{
	int i=0,s=6;
	double k=3.0,len=1.0;
	while(i<=n){
		printf("第%2d次切割为正%5d边形,pi=%.24f\n",i,s,k*sqrt(len));
		s*=2;
		len=2-sqrt(4-len);
		i++;
		k*=2.0;
	}
}
//main
void main()
{
	int n;
	printf("输入切割次数:");
	scanf("%d",&n);
	cycle(n);
}



级数算法求PI
#include"stdio.h"
#include"stdlib.h"
//级数算法求PI
double jishupi()
{
	double pi=1,t=1,s=3,x=1;
	while(x>1e-45){
		x=x*t/s;pi+=x;
		t++;s+=2;
	}
	return 2*pi;
}
//main
void main()
{printf("PI=%.30f\n",jishupi());}
