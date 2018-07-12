#include"stdio.h"

void stdcall_func(int p1,int p2,int p3)
{
	int var1=p1,var2=p2,var3=p3;
	printf("0x%08x\n",&p1);
	printf("0x%08x\n",&p2);
	printf("0x%08x\n",&p3);
	printf("0x%08x\n",&var1);
	printf("0x%08x\n",&var2);
	printf("0x%08x\n",&var3);
}

int main()
{
	stdcall_func(1,2,3);
	return 0;
}