#include"stdio.h"

int sum(int x,int y) { return x+y; }
int minus(int x,int y) { return x-y; }

void test(int (*p)(int,int),int a,int b) 
{
	int result;
	result=(*p)(a,b);
	printf("a=%d,b=%d,result=%d\n",a,b,result);
}

int main()
{
	int a=1,b=2,c=3,d=4,e=-5;
	test(sum,a,b);
	test(minus,c,d);
	test(sum,e,b);

	return 0;
}