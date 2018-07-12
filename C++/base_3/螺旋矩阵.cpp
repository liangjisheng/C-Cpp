// 实现螺旋队列
// 21 22 23 24 25 26
// 20 7  8  9  10 27
// 19 6  1  2  11 ..
// 18 5  4  3  12
// 17 16 15 14 13
// 1的坐标为(0,0),x方向向右为正，y方向向下为正，7的坐标为(-1,-1)
// 2的坐标为(0,1),3的坐标为(1,1),编程实现输入任意一点的坐标(x,y)
// 输出所对应的数字

#include"stdio.h"
#include"math.h"
#define max(a,b) ((a)<(b))?(b):(a)

int foo(int x,int y)
{
	int n=max(abs(x),abs(y)); // 确定每一圈所对应的序列号
	int u=2*n;
	int v=u-1;	// v为所输出的值,v现在为里面一圈右上角的值v=(n-1)*(n-1)
	v=v*v+u;	// v现在为外圈右下角的值
	if(x==-n)
		v+=u+n-y;	// v+=u+n没减y之前的坐标为(-n,0);
	else if(y==-n)
		v+=3*u-n+x;
	else if(y==n)
		v+=n-x;
	else 
		v=v-n+y;
	return v;
}

int main()
{
	int x,y;
	printf("输出螺旋矩阵，1的坐标为(0,0)\n");
	printf("x轴向右为正，y轴向下为正\n");
	printf("\n");
	for(y=-4;y<=4;y++) {
		for(x=-4;x<=4;x++)
			printf("%5d",foo(x,y));
		printf("\n");
	}
	
	printf("输入任意整数坐标求螺旋矩阵的值\n");
	printf("\n请输入坐标:");
	while(scanf("%d%d",&x,&y)==2) {
		printf("螺旋矩阵对应的值:%d\n",foo(x,y));
		printf("请输入坐标:");
	}

	return 0;
}