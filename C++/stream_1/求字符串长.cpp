#include"stdio.h"
int strlen(char *s)
{
	int i;
	for(i=0;s[i]!='\0';)
		i++;
	return i;
}
void main()
{
	char string[50];
	int len;
	printf("输入字符串,直接输入回车结束\n");
	while(1)
	{
	   printf("input the string:");
	   gets(string);
	   len=strlen(string);
	   if(len==0)
		   break;
	   else
		   printf("the string len is:%d\n",len);
	}
}