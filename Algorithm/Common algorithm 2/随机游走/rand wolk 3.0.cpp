#include"stdio.h"
#include"time.h"
#include"stdlib.h"
//#include"Rand Walk 3_3.h"
//#define M 7
//#define N 5
//输出状态
void Print(int *p,int M,int N)
{
	int i,j;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++)
			printf("%3d",*(p+M*i+j));
		printf("\n");
	}
}
//投点函数
void ThrowPoint(int *p,int M,int N,int &row,int &col,int &num_point)
{
	int i,j,point_num;
	printf("请输入要投点所在的行:");
	scanf("%d",&i);
	printf("请输入要投点所在的列:");
	scanf("%d",&j);
	printf("请输入投点个数:");
	scanf("%d",&point_num);
	(*(p+i*M+j))=point_num;
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
	printf("请输入列数:");
	scanf("%d",&N);
	int *p=(int*)malloc(sizeof(int)*M*N);
	//int count[m][n]={0};
	int i,j,k;
	//初始化
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			*(p+M*i+j)=0;
	srand(time(0));//初始化随机种子
	int control;//控制上下左右
	int step;//循环步数
	int PointSum_begin=0;
	//设置初始状态
	/*for(k=0;k<30;k++){//控制投点的个数
	for(i=1;i<M-1;i++)
		for(j=1;j<N-1;j++){
			control=rand()%2;
			if(control==1){
				(*(p+M*i+j))++;
				//count[i][j]++;
				PointSum_begin++;
			}
		}
	}*/
	//输出初始状态
	//	printf("初始状态,共投放了%d个点.\n",PointSum_begin);
	//	Print(p,M,N);
	//投点
	int row,col,point_num;
	ThrowPoint(p,M,N,row,col,point_num);
    //开始随机游走
	//for(step=1;step<=2000;step++)
	while(point_num--!=0){
		int cur_row=row,cur_col=col;//记录当前点坐标
	while(row>0&&row<M-1&&col>0&&col<N-1){
		//for(i=1;i<M-1;i++){
		//	for(j=1;j<N-1;j++){
		//		if(*(p+M*i+j)!=0){
					(*(p+M*row+col))--;//走完之后减1
		control=rand()%4;//控制上下左右
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
	if(row==0)          //up走到边上
		(*(p+row*M+col))++;
	if(col==N-1)        //right走到边上
		(*(p+row*M+col))++;
	if(row==M-1)        //down走到边上
		(*(p+row*M+col))++;
	if(col==0)          //left走到边上
		(*(p+row*M+col))++;
	if(row>0&&row<M-1&&col>0&&col<N-1)//如果没有走到边上
		(*(p+row*M+col))++; 
			//	}
			//}
		//}
		//输出中间状态
		//if(step%10==0){
		//	printf("\n第%d步的状态:\n",step);
		//	Print(p,M,N);
		//}
	}
	row=cur_row,col=cur_col;
	}
    //输出最后状态
	//int PointSum_end=0;
	printf("\n最后状态.\n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
		if((*(p+i*M+j))!=0){
		printf("在(%d,%d)位置有%d个点\n",i,j,*(p+i*M+j));
		}
		}
	}

	for(i=0;i<M;i++){
    	for(j=0;j<N;j++){
			printf("%5d",*(p+i*M+j));
	//		if(*(p+i*M+j)!=0)
	//			PointSum_end+=*(p+i*M+j);
	}
	  printf("\n");
	}
	//printf("共有%d个点.\n",PointSum_end);
	return 0;
}