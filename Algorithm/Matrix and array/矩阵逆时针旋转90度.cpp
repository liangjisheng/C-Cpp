#include"stdio.h"
#define m 5
#define n 2
void main()
{
	int a[m][n],i,j;
	printf("input the a[m][n](m=5,n=2):\n");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
    printf("输出逆时针旋转90度后的矩阵:\n");
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<m;j++)
			printf("%3d",a[j][i]);
		printf("\n");
	}
}

