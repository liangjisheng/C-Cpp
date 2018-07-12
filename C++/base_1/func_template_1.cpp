#include"iostream"
#include"tchar.h"
#include"string"
using namespace std;

template<typename T>
T mymax(const T a,const T b)
{ return a>b?a:b; }

// 利用模板特化，实现特定类型的string的模板函数
template<>
string mymax<string>(const string a,const string b)
{ return a.length() > b.length() ? a : b ; }

int _tmain(int argc,_TCHAR* argv[])
{
	int nA=2,nB=5;
	cout<<"max("<<nA<<","<<nB<<")="
		<<mymax(nA,nB)<<endl;

	float fA=2.2,fB=5.5;
	cout<<"max("<<fA<<","<<fB<<")="
		<<mymax(fA,fB)<<endl;

	double dA=1.2,dB=1.3;
	cout<<"max("<<dA<<","<<dB<<")="
		<<mymax(dA,dB)<<endl;

	// 默认情况下，调用mymax<char*>版本
	string strMax=mymax("chen","jia");
	cout<<"使用普通版本，较大的字符串是\n";
	cout<<"max(\"chen\",\"jia\")="<<strMax<<endl;

	// 显示指明模板参数类型，条用模板特化后的mymax<string>版本
	// 比较字符串长度
	strMax=mymax<string>("chen","jia");
	cout<<"使用模板特化版本，较长的字符串是\n"
		<<"max(\"chen\",\"jia\")="<<strMax<<endl;

	system("pause");
	return 0;
}