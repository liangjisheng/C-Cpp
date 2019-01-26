#include"stdio.h"
#include"time.h"
#include"stdlib.h"
#define N 3
int count[N][N]={0};
int main(int argc,char *argv[])
{
	srand(time(0));
	int control=rand()%4;
	int i=1,j=1;
	switch(control){
	case 0:             
		printf("The Point is go up.\n");
		i=i-1,j=j;
		break;
	case 1:            
		printf("The Point is go right.\n");
		i=i,j=j+1;
		break;
	case 2:             
		printf("The Point is go down.\n");
		i=i+1,j=j;
		break;
	case 3:            
		printf("The Point is go left.\n");
		i=i,j=j-1;
		break;
	}
	if(j==0)
		count[i][j]++;
	if(i==2)
		count[i][j]++;
	if(j==2)
		count[i][j]++;
	if(i==0)
		count[i][j]++;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			printf("%3d",count[i][j]);
		printf("\n");
	}
	return 0;
}