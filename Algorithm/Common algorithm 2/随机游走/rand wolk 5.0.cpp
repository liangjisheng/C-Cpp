#include"stdio.h"
#include"time.h"
#include"stdlib.h"
//投点函数
void ThrowPoint(int *p,int M,int N,int &row,int &col,int &num_point)
{
	int i,j,point_num;
	printf("请输入要投点所在的行:");
	scanf("%d",&i);
	//判断输入的投点行数是否有误？
	while(1){
		if(i<=0||i>=M-1){
			printf("输入的投点行数错误，请重新输入:");
			scanf("%d",&i);
		}
		else break;
	}
	printf("请输入要投点所在的列:");
	scanf("%d",&j);
	//判断输入的列数是否有误？
	while(1){
		if(j<=0||j>=N-1){
			printf("输入的投点列数错误，请重新输入:");
			scanf("%d",&j);
		}
		else break;
	}
	printf("请输入投点个数:");
	scanf("%d",&point_num);
	while(1){
		if(point_num<=0){
		    printf("点数太少，不能随机游走，请重新输入:");
			scanf("%d",&point_num);
		}
	else break;
	}
	(*(p+i*M+j))=point_num;
	//函数返回多个值
	row=i;
	col=j;
	num_point=point_num;
}
//main
int main(int argc,char *argv[])
{
	int M,N;
	printf("请输入行数:");
	scanf("%d",&M);
	//判断输入的行数是否有误？
	while(1){
		if(M<3){
			printf("输入的行数错误，请重新输入:");
			scanf("%d",&M);
		}
		else break;
	}
	printf("请输入列数:");
	scanf("%d",&N);
	//判断输入的列数是否有误？
	while(1){
		if(N<3){
			printf("输入的列数错误，请重新输入:");
			scanf("%d",&N);
		}
		else break;
	}
	int *p=(int*)malloc(sizeof(int)*M*N);//内存分配
	int i,j;
	//初始化为0
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			*(p+M*i+j)=0;
	srand(time(0));//初始化随机种子
	int control;//控制上下左右
	//投点
	int row,col,point_num;
	ThrowPoint(p,M,N,row,col,point_num);
    //开始随机游走
	while(point_num--!=0){
		int cur_row=row,cur_col=col;//记录当前点坐标
	while(row>0&&row<M-1&&col>0&&col<N-1){
		(*(p+M*row+col))--;//走完之后减1
		control=rand()%4;
	switch(control){
	case 0:
		//printf("The Point is go up.\n");
		row=row-1,col=col;
		break;
	case 1:
		//printf("The Point is go right.\n");
		row=row,col=col+1;
		break;
	case 2:             
		//printf("The Point is go down.\n");
		row=row+1,col=col;
		break;
	case 3:            
		//printf("The Point is go left.\n");
		row=row,col=col-1;
		break;
	}
	if(row==0)          //向上走到边上
		(*(p+row*M+col))++;
	if(col==N-1)        //向右走到边上
		(*(p+row*M+col))++;
	if(row==M-1)        //向下走到边上
		(*(p+row*M+col))++;
	if(col==0)          //向左走到边上
		(*(p+row*M+col))++;
	if(row>0&&row<M-1&&col>0&&col<N-1)//如果没有走到边上
		(*(p+row*M+col))++; 
	}
	row=cur_row,col=cur_col;
	}
    //输出最后状态
	printf("\n最后状态.\n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
		if((*(p+i*M+j))!=0)
		{printf("在(%d,%d)位置有%d个点\n",i,j,*(p+i*M+j));}
		}
	}
	//以矩阵形式输出
	for(i=0;i<M;i++){
    	for(j=0;j<N;j++)
			printf("%5d",*(p+i*M+j));
	   printf("\n");
	}
	return 0;
}