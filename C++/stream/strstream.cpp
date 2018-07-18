// strstream.cpp 
#include"iostream"
#include"strstream"
using namespace std;

int main() 
{
	int arraysize=50;
	char * pbuffer=new char[arraysize];
	ostrstream ostr(pbuffer,arraysize,ios::out);
	ostr<<"Hello"<<' ';
	ostr<<99-14<<hex<<' ';
	ostr.setf(ios::showbase);
	// 使用ostrstream输出到流对象的时候,要用ends结束字符串
	ostr<<100<<ends;
	cout<<pbuffer<<endl;
	delete [] pbuffer;

	const char s[]="10 Hello 15 12.23 done";
	istrstream ins(s);
	int i;
	char str[80];
	float f;
	ins>>i>>str;
	cout<<i<<' '<<str<<endl;
	ins>>i>>f>>str;
	cout<<hex<<i<<' '<<f<<' '<<str<<endl;

	system("pause");
	return 0;
}