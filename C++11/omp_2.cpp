#include"stdio.h"
#include"omp.h"
#include"stdlib.h"

void Test(int n) {
	for(int i=0;i<100000000;i++) {}
	printf("%d\n",n);
}

int main()
{
	#pragma omp parallel for
	for(int i=0;i<10;i++)
		Test(i);

	getchar();
	return 0;
}
