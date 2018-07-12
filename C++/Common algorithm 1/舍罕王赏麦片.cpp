#include"stdio.h"
double mai(int n)
{
	int i;
	double s=0,t=1;
	for(i=0;i<n;i++)
	{s+=t;t*=2;}
	return s;
}
void main()
{
	int n;
	double sum;
	printf("舍罕王赏麦片问题.\n");
	printf("input 棋盘总格数:");
	scanf("%d",&n);
	sum=mai(n);
	printf("赏的总麦粒数为:%f\n",sum);
	printf("一共%.2f吨\n",sum/25000/1000);
}