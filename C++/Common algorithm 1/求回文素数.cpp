// 11，101，131，151，181...等对称的数就是回文数，且要找出素数。
#include"stdio.h"
#include"math.h"
//isprime
int isprime(int n)
{
	int i;
	for(i=2;i<=n/2;i++)
	{if(n%i==0)return 0;}
	return 1;
}
//huiwen
int huiwen(int n)
{
	int m,k=1,num=n,sum=0,t;
	int count=0,i;
	while(k>0)
	{k=n-(int)pow(10,count);count++;}
	m=count-1;
	for(i=0;i<m;i++){
		t=num%10;
		sum+=t*(int)pow(10,m-1-i);
		num=num/10;
	}
	if(sum==n){
		if(isprime(n))return 1;
		else return 0;
	}
	else return 0;
}
//main
void main()
{
	int i,count=0;
	printf("output:\n");
	for(i=2;i<50000;i++)
	{
		if(huiwen(i))
		{printf("%7d",i);count++;
		if(count%10==0)printf("\n");}
	}
	printf("\n");
}