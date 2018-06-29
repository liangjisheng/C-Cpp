#include"stdio.h"
int part(char *s,char *pa,int po)
{
	int i=po,j;
	while(s[i]==' ')
		i++;
	if(s[i]!='\0')
	{
		j=0;
		while(s[1]!='\0'&&s[i]!=' ')
		{
			pa[j]=s[i];
			i++;j++;
		}
		pa[j]='\0';
		return i;
	}
	else
		return -1;
}
void main()
{
	char s[50],pa[20];
	int po=0,k=0;
	printf("input the s:");
	gets(s);
	printf("part result:\n");
	while((po=part(s,pa,po))!=-1)
	{
		k++;
		printf("partition %d:%s\n",k,pa);
	}
}