#include"stdio.h"
#define n 3
void main()
{
	int i,j,a[n][n];
	printf("input the array a:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	printf("输出逆时针旋转90度后的矩阵\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%4d",a[j][n-i-1]);
		printf("\n");
	}
}