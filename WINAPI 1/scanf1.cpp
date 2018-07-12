#include"stdio.h"
int main() 
{
	int a,b;
	printf("Input two numbers:");
	while(scanf("%d%d",&a,&b)!=2) {
		fflush(stdin);
		printf("reInput two numbers:");
	}
	printf("%d+%d=%d\n",a,b,a+b);
	return 0;
}