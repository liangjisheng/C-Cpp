// 函数指针无法记住它上一次调用是的状态，使得它无法应用在那些需要
// 对每次调用状态进行维护的场景，例如，无法应用单独的一个函数来计算
// 容器中的所有数据的和，因为它无法得知上一次累加的结果是多少，
// 这是就用到了函数对象。就是定义了函数调用操作法(function-call operator)
// 即operator()的普通类的对象，重载operator()实现函数的所有功能，
// 类具有属性可以将状态数据保存到它的属性中，应用在更广泛的范围
#include"iostream"
#include"tchar.h"
using namespace std;

// 定义模板函数对象
template<typename T>
class mymax {
public:
	T operator()(T a,T b)
	{ return a > b ? a : b; }
};
// 利用函数对象定义函数模板
template<typename T>
T compare(T a,T b,mymax<T>& op)
{ return op(a,b); }

int _tmain(int argc,_TCHAR* argv[])
{
	mymax<int> intmax;	// 定义int型的函数对象
	int nMax=intmax(3,4); // 直接使用函数对象完成比较操作
	cout<<"max="<<nMax<<endl;
	
	nMax=compare(2,3,intmax);	// 在其函数中完成函数对象的使用
	cout<<"max="<<nMax<<endl;

	system("pause");
	return 0;
}