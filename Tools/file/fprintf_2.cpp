
#include<stdio.h>

int main() 
{
	FILE *fp1,*fp2;
	if((fp1=fopen("test.txt","rt"))==NULL) 
	{
		fp2=fopen("report.txt","w");
		fprintf(fp2,"Cannot open this file!\n");
		return 1;
	}
	
	fclose(fp);
	return 0;
}