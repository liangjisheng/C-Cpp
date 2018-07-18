#include"stdio.h"
#include"assert.h"

char* strcpy(char* strDest,const char* strSrc)
{
	assert((strDest!=NULL) && (strSrc!=NULL));
	char* cp=strDest;
	while(*cp++=*strSrc++);
	*cp='\0';
	return strDest;
}

int main()
{
	char* dest=new char[10];
	dest=strcpy(dest,"lishuyu");
	printf("%s\n",dest);	

	char s[]="123456789";
	char d[]="123";
	strcpy(d,s);
	printf("%s\n%s\n",d,s);

	return 0;
}