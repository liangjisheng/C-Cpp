#include"stdio.h"
void main()
{
	int data[9][7]={0,0,0,0,0,0,0,
	                0,3,0,0,0,0,0,
	                0,0,0,0,0,0,0,
	                1,4,0,0,0,0,0,
	                0,0,7,0,0,0,0,
	                0,0,0,0,0,5,0, 
	                0,0,0,0,0,0,0,
	                0,0,0,0,0,0,0,
	                0,0,0,0,0,0,0,};
	int compressdata[10][3],index=0,i,j;
	printf("output the data[9][7]:\n");
	for(i=0;i<9;i++)
	{
		for(j=0;j<7;j++)
			printf("%3d",data[i][j]);
		printf("\n");
	}
	compressdata[0][0]=9;
	compressdata[0][1]=7;
	for(i=0;i<9;i++)
		for(j=0;j<7;j++)
		{
			if(data[i][j]!=0)
				index++;
				compressdata[index][0]=i;
				compressdata[index][1]=j;
				compressdata[index][2]=data[i][j];
		}
		compressdata[0][2]=index;
		printf("output the compressdata:\n");
		for(i=0;i<=index;i++)
		{
			for(j=0;j<3;j++)
				printf("%3d",compressdata[i][j]);
			printf("\n");
		}
}