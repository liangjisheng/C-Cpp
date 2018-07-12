马踏棋盘算法.
#include"stdio.h"
#include"stdlib.h"
typedef struct
{int x,y;}coordinate;
int chessboard[8][8],curstep;
coordinate fangxiang[8]={{-2,1},{-1,2},{1,2},{2,1},
                        {2,-1},{1,-2},{-1,-2},{-2,-1}};//马可能走的八个方位
//马踏棋盘算法
void move(coordinate curpos)
{
	coordinate next;
	int i,j;
	if(curpos.x<0||curpos.x>7||curpos.y<0||curpos.y>7)return;  //越界
	if(chessboard[curpos.x][curpos.y])return;     //已走过
	chessboard[curpos.x][curpos.y]=curstep;
	curstep++;
	if(curstep>64){
		for(i=0;i<8;i++){
			for(j=0;j<8;j++)
				printf("%5d",chessboard[i][j]);
			printf("\n");
		}
		exit(0);
	}
	else{
		for(i=0;i<8;i++){
			next.x=curpos.x+fangxiang[i].x;
			next.y=curpos.y+fangxiang[i].y;
			if(next.x<0||next.x>7||next.y<0||next.y>7){}
			else move(next);
		}
	}
	chessboard[curpos.x][curpos.y]=0;
	curstep--;
}
//main
void main()
{
	int i,j;
	coordinate start;
	printf("马踏棋盘问题求解.\n");
	printf("请先输入马的起始位置(x,y):");
	scanf("%d%d",&start.x,&start.y);
	if(start.x<1||start.x>8||start.y<1||start.y>8)
	{printf("起始位置输入错误,请重新输入.\n");exit(0);}
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			chessboard[i][j]=0;//初始化单元格状态
	start.x--;
	start.y--;
	curstep=1;         //第1步
	move(start);       //求解
}




程序运行结果:
马踏棋盘问题求解.
请先输入马的起始位置(x,y):1 1
    1   38   55   34    3   36   19   22
   54   47    2   37   20   23    4   17
   39   56   33   46   35   18   21   10
   48   53   40   57   24   11   16    5
   59   32   45   52   41   26    9   12
   44   49   58   25   62   15    6   27
   31   60   51   42   29    8   13   64
   50   43   30   61   14   63   28    7
Press any key to continue

马踏棋盘问题求解.
请先输入马的起始位置(x,y):8 8
   53   34   55   30   51   32   15   18
   56   49   52   33   16   19    6   13
   35   54   29   50   31   14   17    4
   48   57   36   41   20    5   12    7
   37   28   47   58   43   22    3   64
   46   59   42   21   40   11    8   23
   27   38   61   44   25    2   63   10
   60   45   26   39   62    9   24    1
Press any key to continue