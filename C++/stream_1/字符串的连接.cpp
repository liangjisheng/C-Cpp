#include"stdio.h"
char *strcat(char *s1,char *s2)
{
	int i,j;
	for(i=0;s1[i]!='\0';i++);
	for(j=0;s2[j]!='\0';j++)
		s1[i+j]=s2[j];
	s1[i+j]='\0';
	return s1;
}
void main()
{
	char s1[100],s2[50];
	printf("input the s1:");
	gets(s1);
	printf("input the s2:");
	gets(s2);
	strcat(s1,s2);
	printf("The merge string is:%s\n",s1);
}