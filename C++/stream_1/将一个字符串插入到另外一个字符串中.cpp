#include"iostream"
#include"iomanip"
#include"cstring"
using namespace std;
int main()
{
	char str1[80]="liangjisheng",str2[40]="liuju";
	int pos,len1=strlen(str1),len2=strlen(str2);
	char *p1=str1,*p2=str2;
	cout<<"str1len="<<len1<<",str2len="<<len2<<endl;
	cout<<"input insert pos(0-"<<len1<<"):";cin>>pos;
	strcat(str2,str1+pos);
	cout<<"str2="<<str2<<endl;
	strcpy(str1+pos,str2);
	cout<<"str1="<<str1<<endl;
	return 0;
}