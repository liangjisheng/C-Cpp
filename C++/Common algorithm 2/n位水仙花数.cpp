#include"stdio.h"
#include"math.h"

// n位水仙花数
void shuixianhuanum(int n)
{
	long i,start,end,num,sum,t;
	int j;
	start = (long)pow(10, n - 1);
	end = (long)pow(10, n) - 1;
	for (i = start; i < end; i++)
	{
		num = i,sum = 0;
		for (j = 0; j < n; j++)
		{
			t=num%10;
			sum+=(long)pow(t,n);
			num=(num-t)/10;
		}
		
		if(sum==i)
			printf("%d\n",i);
	}
}

//main
void main()
{
	int n;
	char again;
s1:printf("求n位水仙花数.\n");
   printf("input n:");
   scanf("%d",&n);
   shuixianhuanum(n);
s2:printf("\n继续玩y/n?");
   fflush(stdin);
   scanf("%c",&again);
   if(again=='y'||again=='Y')goto s1;
   else if(again=='n'||again=='N')goto s3;
   else {printf("输入错误，重新输入.\n");goto s2;}
s3:printf("the game over.\n");
}

