
#include<stdio.h>

int main() 
{
	FILE *fp;
	if((fp=fopen("test.txt","rt"))==NULL) 
	{
		fprintf(stderr,"Cannot open this file!\n");
		return 1;
	}
	fprintf(stderr,"Have open this file!\n");
	
	fclose(fp);
	return 0;
}