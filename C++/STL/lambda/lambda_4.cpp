// 通常来说Lambda表达式没有返回值，参数列表接收STL算法传递进来
// 数据，可以省略返回值类型的定义，若需要返回值，则使用->来定义
// 返回值类型
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

	int nEven=count_if(v.begin(),v.end(),[=](int x) -> bool
	{ return x % 2 == 0; } );
	cout<<"偶数个数为:"<<nEven<<endl;

	int nTotal=0,nAdd=3;
	for_each(v.begin(),v.end(),[&](int x) { nTotal+=(x * nAdd); } );
	cout<<"容器中的数据乘以"<<nAdd<<"之后总和是"<<nTotal<<endl;

	system("pause");
	return 0;
}
