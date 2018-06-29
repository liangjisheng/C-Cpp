#include"stdio.h"

int main()
{
	unsigned char a=250;
	int d;
	printf("unsigned char from 250-260\n");
	for(int i=0;i<10;i++) {
		d=a;
		printf("%d\n",d);
		a++;
	}

	char b=125;
	printf("char from 125-135\n");
	for(int j=0;j<10;j++) {
		d=b;
		printf("%d\n",d);
		b++;
	}
	return 0;
}