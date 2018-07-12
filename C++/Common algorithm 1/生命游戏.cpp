#include"stdio.h"
#include"stdlib.h"
#include"time.h"
#include"conio.h"
#define rowlen 10
#define collen 10
#define dead 0
#define alive 1
int cell[rowlen][collen];
int celltemp[rowlen][collen];
//init
void initcell()
{
	int row,col;
	for(row=0;row<rowlen;row++)
		for(col=0;col<collen;col++)
			cell[row][col]=dead;
    printf("输入一组活细胞的坐标位置,(exit for(-1,-1)):\n");
	while(1){
		printf("输入坐标位置:");
		scanf("%d%d",&row,&col);
		if(row>=0&&row<rowlen&&col>=0&&col<collen)cell[row][col]=alive;
		else if(row==-1||col==-1)break;
		else printf("输入错误,重新输入.\n");
	}
}
//linsum
int linsum(int row,int col)
{
	int count=0,c,r;
	for(r=row-1;r<=row+1;r++)
		for(c=col-1;c<=col+1;c++){
			if(r<0||r>=rowlen||c<0||c>=collen)continue;
			if(cell[r][c]==alive)count++;
		}
	if(cell[row][col]==alive)count--;
	return count;
}
//outputcell
void outcell()
{
	int row,col;
	printf("\n细胞状态.\n");
	for(row=0;row<rowlen;row++){
		for(col=0;col<collen;col++){
			if(cell[row][col]==alive)printf(" 1");
			else printf(" 0");
		}
		printf("\n");
	}
}
//cellfun
void cellfun()
{
	int row,col;
	int count=0;
	for(row=0;row<rowlen;row++){
		for(col=0;col<collen;col++){
			switch(linsum(row,col)){
			case 2:celltemp[row][col]=cell[row][col];break;
			case 3:celltemp[row][col]=alive;break;
			default:celltemp[row][col]=dead;break;
			}
		}
	}
	for(row=0;row<rowlen;row++)
		for(col=0;col<collen;col++){
			cell[row][col]=celltemp[row][col];
			if(cell[row][col]==alive)count++;
		}
	outcell();
	printf("当前状态下,有%d个活细胞.\n",count);
}
//main
int main()
{
	char again;
	printf("生命游戏.\n");
	initcell();
	outcell();
	printf("按任意键开始游戏进行细胞转换.\n");
	getch();
s1:cellfun();
s2:printf("继续生成下一次细胞的状态(y/n)?");
   fflush(stdin);
   scanf("%c",&again);
   if(again=='y'||again=='Y')goto s1;
   else if(again=='n'||again=='N')goto s3;
   else {printf("输入错误,重新输入.\n");goto s2;}
s3:printf("游戏结束.\n");
	return 0;
}