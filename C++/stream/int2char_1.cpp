#include"iostream"
#include"stdio.h"
using namespace std;

int main()
{
	cout<<"input a number:";
	int num;
	cin>>num;
	int n=num;
	int len=0;
	while(n) {
		n=n/10;
		len++;
	}
	char * pstr=new char[len+1];
	pstr[len]='\0';
	itoa(num,pstr,10);
	cout<<"转换后的字符串:"<<pstr<<endl;

	system("pause");
	return 0;
}