#include"stdio.h"
char *strcpy(char *s1,char *s2)
{
	int i;
	for(i=0;s2[i]!='\0';i++)
		s1[i]=s2[i];
	s1[i]='\0';
	return s1;
}
void main()
{
	char s1[50],s2[50];
	printf("input s2:");
	gets(s2);
	strcpy(s1,s2);
	printf("copy the s2 to s1:");
	puts(s1);
}