#include"stdio.h"
//perfectnum
void perfectnum(long n)
{
	long a[50],sum=0,i;
	int k;
	for(k=0;k<50;k++)a[k]=0;
	int j=0;
	for(i=1;i<=n/2;i++)
	{if(n%i==0)sum+=i,a[j++]=i;}
	if(sum==n)
	{
		printf("%ld=%ld",n,a[0]);
		for(j=1;j<50;j++)
		{if(a[j]!=0)printf("+%d",a[j]);}
		printf(".\n");
	}
}
//main
void main()
{
	long n,i;
	printf("input n:");
	scanf("%ld",&n);
	for(i=3;i<=n;i++)
		perfectnum(i);
}