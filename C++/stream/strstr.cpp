// const char* strstr(const char* string,const char* strCharSet);
// 该函数返回主串中字符子串的位置以后的所有字符
#include"stdio.h"

/*const char* strstr(const char* string,const char* strCharSet)
{
	const char* str=string;
	const char* sub=strCharSet;
	while(*str) {
		const char* base=str;
		while(*sub++==*str++ && sub!=NULL && str!=NULL);
		if(sub==NULL) return base;
		else {
			sub=strCharSet;
			str=base+1;
		}
	}
	if(str==NULL) return NULL;
}*/

const char* strstr(const char* string,const char* strCharSet)
{
	for(int i=0;string[i]!='\0';i++) {
		int j=0,temp=i;
		if(string[i]==strCharSet[j]) {
			while(string[i++]==strCharSet[j++]) {
				if(strCharSet[j]=='\0')
					// return &string[temp];
					return &string[i-j];
			}
			i=temp;
		}
	}
}

int main()
{
	char str[]="12345678";
	char sub[]="34";
	const char* re=strstr(str,sub);
	printf("%s\n",re);

	return 0;
}