#include"stdio.h"
void main()
{
	int a[3][3],i,j,k=0,b[9];
	printf("input the a[3][3]:\n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{b[k]=a[i][j];k++;}
	printf("矩阵转换成以行为主的数组:\n");
	for(k=0;k<9;k++)
		printf("%3d",b[k]);
	k=0;
	printf("\n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{b[k]=a[j][i];k++;}
	printf("矩阵转换成以列为主的数组:\n");
	for(k=0;k<9;k++)
		printf("%3d",b[k]);
	printf("\n");
}
另一种方法
#include"stdio.h"
void main()
{
	int a[3][3],i,j,b[9];
	printf("input the a[3][3]:\n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
    for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[3*i+j]=a[i][j];
	printf("将矩阵转换成以行为主的数组:\n");
	for(i=0;i<9;i++)
		printf("%3d",b[i]);
	printf("\n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[3*j+i]=a[i][j];
	printf("将矩阵转换成以列为主的数组:\n");
	for(i=0;i<9;i++)
		printf("%3d",b[i]);
	printf("\n");
}