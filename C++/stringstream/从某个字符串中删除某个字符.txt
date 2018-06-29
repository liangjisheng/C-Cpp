#include"stdio.h"
void main()
{
	char s[20],c;
	int i,k;
	printf("input the s[20]:\n");
	gets(s);
	printf("input the char c:\n");
	c=getchar();
	for(i=0/*,k=0*/;s[i]!='\0';i++)
	{
		if(s[i]==c)
			break;
		/*if(s[i]!=c)
			s[k++]=s[i];*/
	}
	while(s[i]!='\0')
	{
		s[i]=s[i+1];
		i++;
	}
	/*s[i]='\0';*/
	printf("output the s[20]:\n");
	printf("%s\n",s);
}

#include"stdio.h"
void main()
{
	char s[20],c;
	int i,k;
	printf("input the s[20]:\n");
	gets(s);
	printf("input the c:\n");
	c=getchar();
	for(i=0,k=0;s[i]!='\0';i++)
	{
		if(s[i]!=c)
			s[k++]=s[i];
	}
	s[k]='\0';
	printf("output the s[20]:\n");
	printf("%s\n",s);
}