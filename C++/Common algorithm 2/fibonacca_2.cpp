//循环求斐波那契数列

#include"stdio.h"

void main()
{
	long int f1=1,f2=1;
	int i,n;
	printf("input the number:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("%10ld%10ld",f1,f2);
		if(i%2==0)
			printf("\n");
		f1=f1+f2;
		f2=f1+f2;
	}
}

