#include"stdio.h"
//bob
void bqbj(int m,int n)
{
	int x,y,z;
	for(x=0;x<=20;x++)
		for(y=0;y<=33;y++){
			z=n-x-y;
			if(5*x+3*y+z/3==m&&z%3==0)
				printf("公鸡:%d只 母鸡:%d只 小鸡:%d只\n",x,y,z);
		}
}
//main
void main()
{
	int m=100,n=100;
	printf("%d钱买%d鸡问题求解结果为:\n",m,n);
	bqbj(m,n);
}