#include"iostream"
using namespace std;

union {
	unsigned char a;
	unsigned int i;
	unsigned short si;
}u;

int main()
{
	unsigned short int i=0;
	int j=8,p;
	p=j<<1;
	i=i-1;
	cout<<"i="<<i<<endl;
	cout<<"p="<<p<<endl;

	cout<<endl;
	u.i=0xf0f1f2f3;
	cout<<hex<<u.i<<endl;
	cout<<hex<<int(u.a)<<endl;
	cout<<hex<<int(u.si)<<endl;

	system("pause");
	return 0;
}