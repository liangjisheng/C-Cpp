// 求1!+2!+3!+...+n!

#include"stdio.h"
int main()
{
    int i,fact=1,s=0,n;
	printf("input n:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		s=s+fact,fact=fact*(i+1);
	printf("%d\n",s);
	return 0;
}