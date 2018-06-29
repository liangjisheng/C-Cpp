#include"iostream"
#include"tchar.h"
#include"vector"
#include"list"
#include"functional"
#include"algorithm"
using namespace std;

void print(int n) { cout<<n<<' '; }

// 可以接受是对象为参数的函数
/*void PrintMsg( trl::function<void (int)> func ) {
	vector<int> v1;
	v1.push_back(4);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(1);
	// func为传递进来的Lambda表达式
	for_each(v1.begin(),v1.end(),func);
}*/

int _tmain(int argc,_TCHAR* argv[])
{
	// 定义一个可以输出整数的Lambda表达式
	auto show=[](int x) { cout<<x<<' '; };

	vector<int> v;
	int i;
	for(i=0;i<50;i+=3)
		v.push_back(i);

	cout<<"vector Data:"<<endl;
	for_each(v.begin(),v.end(),show);
	cout<<endl;

	list<int> l;
	for(i=0;i<50;i+=3)
		l.push_back(i);

	cout<<"list Data:"<<endl;
	for_each(l.begin(),l.end(),show);
	cout<<endl;

	// Lambda表达式作为参数调用PrintMsg()函数
	//PrintMsg(show);

	system("pause");
	return 0;
}
