#include"iostream"
#include"stdio.h"

char & example(char ch[],int n) { return ch[n]; }

int main() 
{
	using std::cout;
	using std::cin;
	using std::endl;
	cout<<"lishuyu \007\n";		// \007Ϊһ����������
	cout<<"\a";					// \a Ϊ����

	char *p1,*p2;
	p1=new char[20];
	p2=new char[20];
	cout<<"input two string: \n";
	cin>>p1>>p2;
	cout<<p1<<endl;
	cout<<p2<<endl;

	delete []p1;
	delete []p2;

	char ch[]="ABCD";
	cout<<"before:"<<ch<<endl;
	example(ch,2)='c';		// һ���������õĺ���������Ϊ��ֵ
	cout<<"after:"<<ch<<endl;
	return 0;
}