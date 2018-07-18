#include"stdio.h"
char *strrep(char *s1,char *s2,int po)
{
	int i,j;
	po--;
	i=0;
	for(j=po;s1[j]!='\0';j++)
	{
		if(s2[i]!='\0')
		{s1[j]=s2[i];i++;}
		else
			break;
	}
	return s1;
}
void main()
{
	char s1[100],s2[50];
	int po;
	printf("input the s1:");
	gets(s1);
	printf("input the s2:");
	gets(s2);
	printf("input the po:");
	scanf("%d",&po);
	strrep(s1,s2,po);
	printf("The final string is:%s\n",s1);
}