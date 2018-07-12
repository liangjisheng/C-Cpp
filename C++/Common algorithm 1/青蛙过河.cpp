#include"stdio.h"
int count;       //记录青蛙移动的步数
//output
void output(int frog[])
{
	int i;
	printf("第%2d步移动:",count);
	for(i=0;i<=6;i++){
		if(frog[i]==0)printf("   ");
		else if(frog[i]==1)printf(" ->");
		else printf(" <-");
	}
	printf("\n");
	count++;
}
//swap
void swap(int *a,int *b)
{
	int t;
	t=*a,*a=*b,*b=t;
}
//frogmove
void frogmove(int frog[])
{
	int i,moveflag;
	while(frog[0]+frog[1]+frog[2]!=-3||frog[4]+frog[5]+frog[6]!=3)//判断是否结束
	{
		moveflag=1;
		for(i=0;i<6&&moveflag;i++){
			if(frog[i]==1&&frog[i+1]==-1&&frog[i+2]==0)
			{swap(&frog[i],&frog[i+2]);moveflag=0;}
		}
		for(i=0;i<6&&moveflag;i++){
			if(frog[i]==0&&frog[i+1]==1&&frog[i+2]==-1)
			{swap(&frog[i],&frog[i+2]);moveflag=0;}
		}
		for(i=0;i<6&&moveflag;i++){
			if(frog[i]==1&&frog[i+1]==0&&(i==0||frog[i-1]!=frog[i+2]))
			{swap(&frog[i],&frog[i+1]);moveflag=0;}
		}
		for(i=0;i<6&&moveflag;i++){
			if(frog[i]==0&&frog[i+1]==-1&&(i==5||frog[i-1]!=frog[i+2]))
			{swap(&frog[i],&frog[i+1]);moveflag=0;}
		}
		if(moveflag==0)output(frog);
	}
}
//main
void main()
{
	int frog[7]={1,1,1,0,-1,-1,-1},i;
	printf("青蛙过河问题求解.\n");
	printf("青蛙初始位置如下:\n");
	printf("           ");
	for(i=0;i<=6;i++){
		if(frog[i]==0)printf("   ");
		else if(frog[i]==1)printf(" ->");
		else printf(" <-");
	}
	printf("\n");
	count=1;
	frogmove(frog);        //求解
}