#include"iostream"
#include"string"
#include"stdlib.h"
#include"time.h"
using namespace std;

int main()
{
	/*string str1("Good Morning");
	wstring wstr1(L"中国");
	cout<<str1<<endl;
	// 设定字符的编码方式
	wcout.imbue(locale("chs"));
	wcout<<wstr1<<endl;

	int nLength=str1.length();
	cout<<nLength<<endl;
	string::size_type nPos=str1.find('o');
	cout<<"在位置"<<nPos<<"有一个字符o"<<endl;

	enum Weekday { mon,tue,wed,thu,fri,sat,sun};
	Weekday nDay=tue;
	cout<<nDay<<endl;

	enum weekday { sun1,mon1,tue1,wed1,thu1,fri1,sat1} a,b,c;
	a=sun1; b=mon1; c=tue1;
	cout<<a<<' '<<b<<' '<<c<<endl;*/

	srand(time(NULL));
	enum body {a,b,c,d};
	body month[31];
	int i;
	for(i=0;i<31;i++) {
		int num=rand()%4;
		if(num==1) month[i]=a;
		else if(num==2) month[i]=b;
		else if(num==3) month[i]=c;
		else month[i]=d;
	}

	for(i=0;i<31;i++)
		cout<<month[i]<<' ';
	cout<<endl;

	for(i=0;i<31;i++) {
		switch(month[i]) {
		case a: cout<<"a"<<' '; break;
		case b: cout<<"b"<<' '; break;
		case c: cout<<"c"<<' '; break;
		case d: cout<<"d"<<' '; break;
		default: break;
		}
	}
	cout<<endl;

	system("pause");
	return 0;
}