#include"stdio.h"
void jttl(int head,int foot,int *ji,int *tu)
{*tu=(foot-2*head)/2;*ji=head-*tu;}
void main()
{
	int head,foot,ji,tu;
	printf("input head foot:");
	scanf("%d%d",&head,&foot);
	jttl(head,foot,&ji,&tu);
	printf("ji=%d,tu=%d\n",ji,tu);
}