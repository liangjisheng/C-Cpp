#include"stdio.h"
//isprime
int isprime(int n)
{
	int i;
	for(i=2;i<=n/2;i++)
	{if(n%i==0)return 0;}
	return 1;
}
//primefactor
void primefactor(int n)
{
	int i;
	if(isprime(n))printf("%d*",n);
	else{
		for(i=2;i<=n/2;i++){
			if(n%i==0){
				printf("%d*",i);
				if(isprime(n/i))
				{printf("%d",n/i);break;}
				else primefactor(n/i);
				break;
			}
		}
	}
}
//main
void main()
{
	int n;
	printf("input n:");
	scanf("%d",&n);
	printf("n=%d=",n);
	primefactor(n);
	printf("\n");
}