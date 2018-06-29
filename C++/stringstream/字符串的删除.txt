#include"stdio.h"
char *strdel(char *s,int po,int len)
{
	int i;
	for(i=po+len;s[i]!='\0';i++)
		s[i-len]=s[i];
	s[i-len]='\0';
	return s;
}
void main()
{
	char s[50];
	int len,po;
	printf("input the s:");
	gets(s);
	printf("input the po and len:");
	scanf("%d%d",&po,&len);
	strdel(s,po,len);
	printf("output the s:%s\n",s);
}