
#include <iostream>
#include <iomanip>

int main()
{
	std::cout << "test" << std::endl;

	// <<输出操作符把它本身的调用操作转换为一个以
	// stream为参数的函数调用 std::endl(std::cout)
	std::cout << std::endl;

	// 如果全局空间没有这个函数，编译器会自动在其参数定义
	// 所在的命名空间中查找(Koenig lookup)法则
	endl(std::cout);

	using std::ios;
	using std::cout;
	using std::endl;
		
	// save current format flags
	ios::fmtflags oldFlags = cout.flags();

	int x = 123;
	// do some changes
	cout.setf(ios::showpos | ios::showbase | ios::uppercase);
	cout.setf(ios::internal | ios::adjustfield);
	cout << std::hex << x << std::endl;
	
	// restore saved format flags
	cout.flags(oldFlags);
	cout << std::endl;

	// 字符宽度会恢复为默认值，填充字符和位置调整方式不变
	// 除非你明白的对他们做了修改
	cout << std::setw(8) << std::setfill('_') << -3.14
		<< ' ' << 42 << std::endl;
	cout << std::setw(8) << "sum: " 
		<< std::setw(8) << 42 << std::endl;

	cout << 12345678.9 << endl;
	cout.setf(ios::showpos | ios::uppercase);
	cout << 12345678.9 << endl;

	system("pause");
	return 0;
}