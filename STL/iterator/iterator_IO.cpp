#include"iostream"
#include"string"
#include"iterator"
using namespace std;

// 引用标准输出流cout的迭代器
ostream_iterator<string> oo_string(cout);
// 引用标准输入流cin的迭代器,输入迭代器成对出现，
// 必须提供另一个istream_iterator表示输入的结束
// 这就是那个默认的istream_iterator<string> eos;
istream_iterator<string> ii_string(cin);

int main()
{
	cout<<"begin of main()"<<endl;
	*oo_string="Hello ";	// 相当于cout<<"Hello ";
	++oo_string;
	*oo_string="world!\n";	// 相当于cout<<"world!\n";

	// 从输入流中读入,在进入主函数之前就必须输入
	string s1=*ii_string;
	++ii_string;
	string s2=*ii_string;
	cout<<s1<<' '<<s2<<endl;

	cout<<"end of main()"<<endl;
	system("pause");
	return 0;
}