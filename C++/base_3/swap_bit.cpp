#include"stdio.h"

int main()
{
	unsigned short a=0xABCD;
	unsigned short b,c,d;
	b=(a<<8)&0xff00;
	c=(a>>8)&0x00ff;
	d=b|c;
	printf("%x\n",a);
	printf("%x\n",b);
	printf("%x\n",c);
	printf("%x\n",d);

	getchar();
	return 0;
}