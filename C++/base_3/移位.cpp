#include"stdio.h"
#include"iostream"

int main()
{
	int a=12,b=15;
	int c=a-b;
	int d=-c;

	int c_r=unsigned(c);
	printf("%d\n",c_r);
	c_r=c_r >> (sizeof(int)*8-1);
	printf("%d\n",c_r);

	int d_r=unsigned(d);
	printf("%d\n",d_r);
	d_r=d_r>>(sizeof(int)*8-1);
	printf("%d\n",d_r);

	system("pause");
	return 0;
}