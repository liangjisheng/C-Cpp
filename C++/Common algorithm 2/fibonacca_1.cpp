// 递归求斐波那契数列：

#include"stdio.h"

long int f(int n)
{
	if(n==1)
		return 1;
	else if(n==2)
		return 1;
	else
		return f(n-1)+f(n-2);
}

void main()
{
	int n,i=1,count=0;
	printf("input a number:");
	scanf("%d",&n);
	printf("%10d",i);
	count++;
	printf("%10d",i);
	count++;
	for(i=3;i<=n;i++)
	{
		printf("%10ld",f(i));
		count++;
		if(count%5==0)
			printf("\n");
	}
	printf("\n");
}

