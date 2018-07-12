#include"stdio.h"
#include"iostream.h"
#include"windows.h"

void func() {
	char *buffer=new char[128];
	char bufflocal[128];
	static char buffstatic[128];
	printf("0x%08x\n",buffer);
	printf("0x%08x\n",bufflocal);
	printf("0x%08x\n",buffstatic);
}

int main()
{
	func();
	return 0;
}