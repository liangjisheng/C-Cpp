// _itoa(),_itow(),_ltow等都可以将数字转换成字符串
// 但更多的时候使用stringstream类来完成数字到字符串的转换
#include"iostream"
#include"sstream"
#include"iomanip"
using namespace std;

int main()
{
	float fA=1.19830706;
	float fB=1.19830703;
	stringstream sstr;
	// 设定浮点的输出精度，并将fA输出到stringstream对象
	sstr<<fixed<<setprecision(8)<<fA;
	string strA;
	// 将浮点数fA转换为字符串strA
	sstr>>strA;
	// 清空stringstream对象，开始第二次转换
	sstr.clear();
	sstr<<fB;
	string strB;
	sstr>>strB;

	cout<<"fA="<<strA<<endl;
	cout<<"fB="<<strB<<endl;
	// 通过转换后的字符串比较字符串的大小
	if(strA==strB)
		cout<<fA<<"="<<fB<<endl;
	else if(strA>strB)
		cout<<fA<<">"<<fB<<endl;
	else 
		cout<<fA<<"<"<<fB<<endl;

	string str("1.1983");
	sstr.clear();
	sstr<<str;
	sstr>>fA;
	cout<<fA<<endl;

	system("pause");
	return 0;
}