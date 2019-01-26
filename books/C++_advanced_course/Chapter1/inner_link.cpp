
#include <iostream>

using namespace std;

template<char* p>
class Exmaple
{
public:
	void display() { cout << *p << endl; }
};

static char c = 'a';


namespace { char c1 = 'a'; }


int main()
{
	// static 修饰的变量(函数)具有内部链接特性，而具有内部链接特性的变量是
	// 不能用来实例化一个模板的非类型参数，下面会出现编译错误
	// Exmaple<&c> a;
	// a.display();

	// 下面的代码可以正常编译并输出，由此看出包含在匿名名字空间中的全局变量(函数)
	// 具有外部链接特性，而用static修饰的变量或者函数具有内部链接特性，
	Exmaple<&c1> a1;
	a1.display();

	system("pause");
	return 0;
}