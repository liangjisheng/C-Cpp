// 倒换字符串 i come from tianjin. 倒换后变成tianjin. from come i
#include"iostream"
#include"stdio.h"
#include"string.h"
using namespace std;

void reverse(char* str)
{
	int len=strlen(str);
	int i=0;
	char ch;
	while(i<len/2) {
		ch=str[i];
		str[i]=str[len-i-1];
		str[len-i-1]=ch;
		i++;
	}
}

void switching(char* str)
{
	char word[32]={0};
	int len=strlen(str);
	int j=0,base=0;
	for(int i=0;i<len;i++) {
		base=i;j=0;
		while(str[i]!=' ' && str[i])
			word[j++]=str[i++];
		word[j]='\0';
		reverse(word);
		j=0;
		while(base<i)
			str[base++]=word[j++];
	}
}

int main()
{
	char str[]="12345 asdf";
	cout<<str<<endl;
	reverse(str);
	// cout<<str<<endl;
	switching(str);
	cout<<str<<endl;

	return 0;
}