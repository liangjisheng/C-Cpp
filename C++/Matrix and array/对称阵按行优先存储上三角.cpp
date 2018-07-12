#include"stdio.h"
#define n 3
void main()
{
	int a[n][n],i,j,ap[n*(n+1)/2],k=0;
	printf("input the a[n][n](nΪ3):\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{ap[k]=a[i][j];k++;}
	}
	printf("output the ap[n*(n+1)/2]:\n");
	for(i=0;i<n*(n+1)/2;i++)
		printf("%3d",ap[i]);
	printf("\n");
}