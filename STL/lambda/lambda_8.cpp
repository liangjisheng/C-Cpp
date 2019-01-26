// 如果需要与Lambda表达式传递多个数据，可以在[]的第一位设置
// 一个默认的传递方式，然后在分别指定各个变量的传递方式
// 例如，想在默认情况下使用传引用的方式，但是其中一个变量使用传值的方式
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

	int nTotal=0,nAdd=3;
	for_each(v.begin(),v.end(),[&](int x) { nTotal+=(x * nAdd); } );
	cout<<"容器中的数据乘以"<<nAdd<<"之后总和是"<<nTotal<<endl;

	system("pause");
	return 0;
}
