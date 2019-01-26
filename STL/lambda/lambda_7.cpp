// 如果想在Lambda表达式中修改当前作用域内的变量，就需要使用
// 传引用的方式来定义Lambda表达式，这时使用[&]来代替[=]来说明
// Lambda表达式使用传引用方式使用变量，可以修改变量的值
#include"iostream"
#include"tchar.h"
#include"vector"
#include"algorithm"
using namespace std;

void print(int n) { cout<<n<<' '; }

int _tmain(int argc,_TCHAR* argv[])
{
	vector<int> v;
	for(int i=0;i<50;i+=3)
		v.push_back(i);

	cout<<"Data:"<<endl;
	for_each(v.begin(),v.end(),print);
	cout<<endl;

	int nTotal=0;
	for_each(v.begin(),v.end(),[&](int x) { nTotal+=x; } );
	cout<<"sum of data="<<nTotal<<endl;

	system("pause");
	return 0;
}
