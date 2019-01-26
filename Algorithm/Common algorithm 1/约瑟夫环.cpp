#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"malloc.h"
#define num 41
#define killman 3
//josephus
void josephus(int alive)
{
	int man[num]={0},count=1,i=0,pos=-1;
	while(count<=num){
		do{
			pos=(pos+1)%num;
			if(man[pos]==0)i++;
			if(i==killman){i=0;break;}
		}while(1);
		man[pos]=count;
		printf("第%2d个人自杀,编号为:%2d",pos+1,man[pos]);
		if(count%2!=0)printf("->");
		else printf("->\n");
		count++;
	}
	printf("\n");
	printf("要存活的人需排在一下序号上:\n");
	alive=num-alive;
	for(i=0;i<num;i++)
	{if(man[i]>alive)printf("初始编号:%d,约瑟夫环编号:%d\n",i+1,man[i]);}
}
//main
void main()
{
	int alive;
	printf("约瑟夫环问题求解.\n");
	printf("input the alive num:");
	scanf("%d",&alive);
	josephus(alive);
}