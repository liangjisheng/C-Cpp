#include"stdio.h"
long peach(int n)
{
	if(n==1)return 1;
	else return (peach(n-1)+1)*2;
}
void main()
{
	int n;
	printf("input n:");
	scanf("%d",&n);
	printf("共摘了%ld个桃子\n",peach(n));
}