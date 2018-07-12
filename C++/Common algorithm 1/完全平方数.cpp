//一个整数10万以内，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
#include"stdio.h"
#include"math.h"
int main(int argc,char *argv[])
{
	int i,j,k;
	//printf("%d\n",int(sqrt(8)));
	for(i=1;i<=100000;i++){
		j=int(sqrt(i+100));
		k=int(sqrt(i+168));
		if((j*j==i+100)&&(k*k==i+168))
			printf("%d ",i);
	}
	printf("\n");
	return 0;
}
