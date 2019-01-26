日本数学家谷角在研究自然数时发现了一个现象:对于任何一个自然数n，如果n为偶数，则将其除以2；如果n为奇数，则将其乘以3，然后再加1。按照以上方法经过有限次运算后，总可以得到自然数1。人们将谷角静夫的这一发现称做“谷角猜想”。
下面程序为验证谷角猜想。
#include"stdio.h"
void main()
{
	int n,count=0;
	printf("input the n:");
	scanf("%d",&n);
	while(n!=1)
	{
		if(n%2==0)
		{n=n/2;printf("%7d",n);count++;}
		else
		{n=3*n+1;printf("%7d",n);count++;}
		if(count%5==0)
			printf("\n");
	}
	printf("\n");
}
