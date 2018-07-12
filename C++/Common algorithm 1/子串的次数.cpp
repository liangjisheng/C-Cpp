//计算字符串中子串出现的次数
#include"iostream"
#include"cstring"
#include"string"
using namespace std;
int main(int argc,char *argv[])
{
	char str1[]="liangliangliangliangliang",str2[]="li";
	char *p1=str1,*p2=str2;
	int count=0;
	while(*p1!='\0'){
		while(*p2!='\0'){
			if(*p1==*p2)p1++,p2++;
			else break;
		}
		if(*p2=='\0')count++;
		else p1++;
		p2=str2;
	}
	cout<<"字符串"<<str2<<"在"<<str1<<"总共出现了:"<<count<<"次"<<endl;
	return 0;
}