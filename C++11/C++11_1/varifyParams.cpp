
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// 可变参数模板
template<typename... Types>
class myVariadicTemplate
{

};

// 可以使用任意数量的类型来实例化myVariadicTemplate
myVariadicTemplate<> c0;
myVariadicTemplate<int> c1;
myVariadicTemplate<string, double> c2;
myVariadicTemplate<char, int, long, double> c3;


// 类型安全的可变长度参数列表
void handleValue(int val) 
{
	cout << "Integer: " << val << endl; 
}

void handleValue(double val)
{
	cout << "double: " << val << endl;
}

void handleValue(const std::string& val)
{
	cout << "string: " << val << endl;
}


template<typename T>
void processValues(T arg)		// Base case基本情形
{
	handleValue(arg);
}


// 下面两行的...表示参数包可以接受可变数目的参数
template<typename T1, typename... Tn>
void processValues(T1 arg1, Tn... args)
{
	handleValue(arg1);
	// ...表示参数包的扩展。运算符会解包/展开参数包args，得到各个
	// 参数。它基本上提取出运算符左边的内容，为包中的每个模板参数
	// 重复该内容，并用逗号分割开。模板的实现是递归的，需要一个只
	// 接受单个模板参数的基本情形(Base case)
	processValues(args...);
}


// test
int main()
{
	processValues(1, 2, 3.45, "test", 1.1f);

	system("pause");
	return 0;
}