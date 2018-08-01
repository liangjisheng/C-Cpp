// tmpnam.cpp -- generate a temporary file
// temfile generate a temporary file
#include"stdio.h"

int main()
{
	char name[80];
	tmpnam(name);
	printf("Temporary name:%s\n",name);

	char buf[L_tmpnam];
	char *p;
	p=tmpnam(buf);
	puts(p);
	printf("%p\n",p);
	puts(tmpnam(NULL));
	printf("%p\n",p);
	
	getchar();
	return 0;
}