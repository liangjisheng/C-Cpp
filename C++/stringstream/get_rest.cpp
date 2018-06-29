// ´ÓstrÖĞÉ¾³ı×Ö·û´®sub
#include"stdio.h"
#include"string.h"

int main()
{
	char uu[20],*p,*sub="ask",*str="askdaskaskdasg";
	char *str2;
	int n=0,i=0;

	p=sub;
	str2=str;
	while(*str2) {
		while(*p) {
			if(*p==*str2) break;
			p++;
		}
		if(*p=='\0')
			uu[i++]=*str2;
		str2++;
		p=sub;
	}

	uu[i]=0;
	printf("%s\n",uu);

	return 0;
}