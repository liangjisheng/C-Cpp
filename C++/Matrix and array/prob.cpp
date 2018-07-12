#include"stdlib.h"
#include"stdio.h"
#define LOOP 1000

int main()
{
	int count=0;
	for(int i=0;i<LOOP;i++){
		int x=rand();
		int y=rand();
		if(x*x+y*y<RAND_MAX*RAND_MAX) count++;
	}

	// 概率为pi/4
	printf("%d\n",count);
	printf("%lf\n",(double)count/LOOP);

	return 0;
}