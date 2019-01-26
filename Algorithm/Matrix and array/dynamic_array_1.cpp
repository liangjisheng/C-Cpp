#include"stdio.h"
#include"stdlib.h"

int main() {
	int x,y,i,j;
	double **a;
	printf("input row and col number:");
	scanf("%d%d",&x,&y);
	a=(double**)malloc(sizeof(double*) * x);
	for(i=0;i<x;i++)
		*(a+i)=(double*)malloc(sizeof(double)*y);
	printf("input the elements of matrix:\n");
	for(i=0;i<x;i++) {
		for(j=0;j<y;j++)
			scanf("%lf",&a[i][j]);
	}
	printf("output the matrix:\n");
	for(i=0;i<x;i++) {
		for(j=0;j<y;j++)
			printf("%.2lf   ",a[i][j]);
		printf("\n");
	}
	// delete 
	for(i=0;i<x;i++)
		free(*(a+i));
	free(a);
	return 0;
}