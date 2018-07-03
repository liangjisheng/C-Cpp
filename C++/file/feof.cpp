
#include<stdio.h>

int main() {
	FILE *stream;
	char ch;
	stream=fopen("test.txt","r");
	while(!feof(stream)) 
	{
		ch=fgetc(stream);
		printf("%c",ch);
	}
	printf("\n");
	if(feof(stream)) 
		printf("Have reached the end of file!\n");
	
	fclose(stream);
	return 0;
}