#include"stdio.h"
#include"string.h"
void reverse(char *s)
{
	int i,k;
	char ch;
	k=strlen(s);
	for(i=0;i<k/2;i++)
	{
		ch=*(s+i);
		*(s+i)=*(s+k-1-i);
		*(s+k-1-i)=ch;
	}
}
void main()
{
	FILE *fp;
	char str[50];
	if((fp=fopen("rev","w+"))==NULL)
		printf("Create file error!\n");
	printf("input the str[50]:\n");
	gets(str);
	fprintf(fp,"%s",str);
	reverse(str);
	printf("output the reverse str:\n");
	puts(str);
	fprintf(fp,"%s",str);
	fclose(fp);

	FILE *p;
	p=fopen("rev","r+");
	if(p==NULL)
		printf("open the file error!!\n");
	char string[50];
	fscanf(p,"%s",string);
	printf("output the string:\n");
	puts(string);
}