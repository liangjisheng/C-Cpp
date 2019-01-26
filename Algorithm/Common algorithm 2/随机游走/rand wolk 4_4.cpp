#include"stdio.h"
#include"time.h"
#include"stdlib.h"
#define N 4
int count[N][N]={0};
int main(int argc,char *argv[])
{
	srand(time(0));//初始化随机种子
	int control;//控制上下左右
	int i,j,k;
	int step;//循环步数
	int PointSum_begin=0;
	//设置初始状态
	for(k=0;k<10;k++){//控制投点的个数
	for(i=1;i<N-1;i++)
		for(j=1;j<N-1;j++){
			control=rand()%2;
			if(control==1){
				count[i][j]++;
				PointSum_begin++;
			}
		}
	}
	//输出初始状态
		printf("初始状态,共投放了%d个点.\n",PointSum_begin);
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			printf("%3d",count[i][j]);
		printf("\n");
	}
    //开始随机游走
	for(step=1;step<=30;step++){//控制步数
		//从内层开始循环
		for(i=1;i<N-1;i++){
			for(j=1;j<N-1;j++){
				if(count[i][j]!=0){
					count[i][j]--;//走完之后减1
					int ii=i,jj=j;//记录当前点坐标
		control=rand()%4;//控制上下左右
	switch(control){
	case 0:
		//printf("The Point is go up.\n");
		ii=ii-1,jj=jj;
		break;
	case 1:            
		//printf("The Point is go right.\n");
		ii=ii,jj=jj+1;
		break;
	case 2:             
		//printf("The Point is go down.\n");
		ii=ii+1,jj=jj;
		break;
	case 3:            
		//printf("The Point is go left.\n");
		ii=ii,jj=jj-1;
		break;
	}
	if(ii==0)          //up走到边上
		count[ii][jj]++;
	if(jj==N-1)        //right走到边上
		count[ii][jj]++;
	if(ii==N-1)        //down走到边上
		count[ii][jj]++;
	if(jj==0)          //left走到边上
		count[ii][jj]++;
	if(ii>0&&ii<N-1&&jj>0&&jj<N-1)//如果没有走到边上
		count[ii][jj]++; 
				}
			}
		}
	}
    //输入最后状态
	int PointSum_end=0;
	printf("\n最后状态.\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%3d",count[i][j]);
			if(count[i][j]!=0)
				PointSum_end+=count[i][j];
		}
		printf("\n");
	}
	printf("共有%d个点.\n",PointSum_end);
	return 0;
}