
// 以下是C++中常用的声明语句：
// int foo(int, int);				// 函数前置声明
// typedef int Int;					// typedef声明
// class bar;						// 类前置声明
// extern int g_var;				// 外部引用声明
// friend test;						// 友元声明
// using std::cout;					// 名字空间引用声明

// C++中声明和定义所作用的对象有三种：变量、函数和数据类型,可以把这三种对象
// 称为程序元素，声明可以出现多次，而定义只能出现一次.声明一个程序元素是通知
// 当前作用域内存在这样一个程序元素(从而将该程序元素引入作用域),并提供该程序
// 元素的必要信息(而不是全部实现细节). 而定义一个程序元素，则是提供该程序元素
// 在当前作用域内的唯一描述,包括它的实现细节


#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

extern int i;					// declare
extern int j;					// declare

void greet(string name);

class A;


int main()
{
	cout << i << endl;
	cout << j << endl;
	greet("test");

	// 一个类被声明了之后，可以用它来声明其它的标识符，但不允许利用它来
	// 定义对象，也不允许使用类的任何成员
	// A a;					// error
	// a.show();			// error

	system("pause");
	return 0;
}


// 全局静态变量的声明和定义必须出现在同一个源文件中，
// 而全局变量，其声明和定义语句允许出现在不同的源文件中
int i = 5;						// define
static int j = 6;				// define


static void greet(string name) { cout << "hello " << name << endl; }


// 类A具有全局作用域，但它的所有成员的有效范围是从定义类的地方开始的.
// 由于不知道sizeof(A)的大小，也不知道类的构造函数的定义，所以在定义
// 类A之前就使用它来定义对象是不允许的
class A
{
	int num;
public:
	A() { num = 5; }
	void show() { cout << num << endl; }
};


