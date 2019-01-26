#include"stdio.h"
void main()
{
	int i,j,s,count=0;
	int n1,n2;
	printf("求两个数之间的完数\n");
	printf("input the n1 and n2:");
	scanf("%d%d",&n1,&n2);
	for(i=n1;i<=n2;i++)
	{
		s=i;
		for(j=1;j<=i/2+1;j++)
		{
			if(i%j==0)
				s=s-j;
		}
		if(s==0)
		{
			count++;
			if(count%5==0&&count>0)
				printf("\n");
			printf("[%d]",i);
		}
	}
	printf("\n");
}


另一种方法
#include"stdio.h"
#include"math.h"
void main()
{
	int a[20],i,j,sum,k;
	for(i=2;i<=1000;i++)
	{
		sum=0;
		k=0;
		for(j=1;j<=i/2;j++)
		{
			if(i%j==0)
			{a[k++]=j;sum+=j;}
		}
		if(i==sum)
		{
			printf("%d=",i);
			for(j=0;j<k;j++)
				printf("+%d",a[j]);
			printf("\n");
		}
	}
}