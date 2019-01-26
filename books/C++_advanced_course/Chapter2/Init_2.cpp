
// 引用相当于指针常量，所以定义引用时也必须同时初始化，定义常对象的时候
// 相应的构造函数必须显示定义

#include <iostream>

using std::cout;
using std::endl;
using std::cin;


class A
{
	int num;
public:
	void show() const { cout << num << endl; }
};


void test()
{
	// 由于程序的控制结构可能导致某些变量无法初始化，将引发编译错误
	int i;
	cout << "input a number:";
	cin >> i;
	if(8 == i)
		goto disp;
	int j = 9;
disp:
	cout << i + j << endl;			// runtime error, j not init
}


void test_1()
{
	// C++中并没有强制switch语句的个case分支使用break;所以在一个case分支中
	// 定义的变量是可能被其它分支的语句所使用的。由于case分支被执行的随机性
	// 无法保证变量有合适的初值，所以除非只有一个case分支，否则不要在case分支
	// 中定义局部变量

	int i;
	cout << "input a number;";
	cin >> i;
	switch(i)
	{
	case 1: 
		int j = 6;
		cout << j << endl;
		break;
	//case 2:
		//cout << "hello" << endl;
	}
}


int main()
{
	// 没有显示定义参数个数为0的构造函数，而编译提供的默认构造函数实际上什么
	// 初始化工作没做，由于a是常对象，如果构造函数不做初始化工作，他就永远没有
	// 机会获得有意义的值
	const A a;
	a.show();

	test();

	test_1();
	
	system("pause");
	return 0;
}