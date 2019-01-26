// Lambda表达式
#include"iostream"
#include"tchar.h"
#include"vector"
#include"algorithm"
using namespace std;

int _tmain(int argc,_TCHAR* argv[])
{
	double nTotal=0;
	int nCount=0;
	vector<int> vec;
	for(int i=0;i<50;i+=3)
		vec.push_back(i);

	// Lambda表达式类似于函数指针和函数对象，可以应用于STL上
	// 对算法进行自定义，Lambda表达式可以在使用函数的地方对其 
	// 进行定义，使代码更加流畅，同时可以在Lambda表达式中访问
	// Lambda表达式之外的数据，解决函数执行过程中状态数据保存问题，
	// Lambda表达式兼顾函数指针和函数对象的优点 
	for_each(vec.begin(),vec.end(),
		[&](int data)
	{
		nTotal+=data;
		nCount++;
	});
	cout<<"nCount="<<nCount<<endl;
	cout<<"Average="<<nTotal/nCount<<endl;

	system("pause");
	return 0;
}
