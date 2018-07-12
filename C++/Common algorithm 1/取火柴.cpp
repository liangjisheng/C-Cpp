//常胜将军取火柴（计算机一直在赢）
#include"stdio.h"
int com,user,last;
//jiangjun
void jiangjun()
{
	while(1){
		printf("目前火柴还有%d个.\n",last);
		printf("用户取火柴:");
		scanf("%d",&user);
		if(user<1||user>4||user>last)
		{printf("取的火柴数有问题.\n\n");continue;}
		last=last-user;
		if(last==0)
		{printf("用户取了最后一个火柴，计算机赢了.\n");break;}
		else{
			com=5-user;
			last=last-com;
			printf("计算机取火柴数量:%d\n",com);
			if(last==0)
			{printf("计算机取了最后一个火柴，用户赢了.\n");break;}
		}
	}
}
//main
void main()
{
	int num;
	printf("常胜将军问题.\n");
	printf("取火柴数只能在1到4之间.\n");
	printf("输入火柴总数:");
	scanf("%d",&num);
	last=num;
	jiangjun();
}


取火柴，不是计算机一直在赢
#include"stdio.h"
#include"stdlib.h"
#include"time.h"
int com,user,last;
//quhuochai
void quhuochai()
{
	srand(time(NULL));
	while(1){
		printf("\n目前还有%d根火柴\n",last);
		printf("用户取火柴数量:");
		scanf("%d",&user);
		if(user<0||user>4||user>last)
		{printf("输入错误，重新输入:\n");continue;}
		last=last-user;
		if(last==0)
		{printf("用户取了最后一根火柴，电脑赢了.\n");break;}
		else{
			if(last>4)com=rand()%5;
			else if(last<=1)com=1;
			else com=last-1;
		last=last-com;
		printf("电脑取了%d根火柴.\n",com);
		if(last==0)
		{printf("电脑取了最后一根火柴，用户赢了.\n");break;}
		}
	}
}
//main
void main()
{
	int num;
	printf("取火柴游戏.\n");
	printf("输入火柴的总数量:");
	scanf("%d",&num);
	last=num;
	quhuochai();
}