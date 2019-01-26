#include"stdio.h"
void main()
{
	int a[5][4],b[4][6],i,j,k,c[5][6];
	printf("input the a[5][4]:\n");
	for(i=0;i<5;i++)
		for(j=0;j<4;j++)
			scanf("%d",&a[i][j]);
	printf("input the b[4][6]:\n");
	for(i=0;i<4;i++)
		for(j=0;j<6;j++)
			scanf("%d",&b[i][j]);
	for(i=0;i<5;i++)
		for(j=0;j<6;j++)
		{
			c[i][j]=0;
			for(k=0;k<4;k++)
				c[i][j]+=a[i][k]*b[k][j];
		}
	printf("output the c[5][6]:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<6;j++)
			printf("%5d",c[i][j]);
		printf("\n");
	}
}
