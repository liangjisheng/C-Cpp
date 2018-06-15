
// 显示极值
#include<iostream>
#include<limits>
#include<string>

// numeric_limits是一个通用的模板，为所有的类型提供默认极值
// 对于各具体类型的极值，有特化版本(specialization)提供,
// 通用的numeric_limits template及其特化版本都被放在<limits>
// 头文件中

using std::cout;
using std::endl;
using std::boolalpha;
using std::numeric_limits;
using std::string;

int main()
{
	// use textual representation for bool
	cout << boolalpha;

	cout << "max(short): " << numeric_limits<short>::max() << endl;
	cout << "max(int): " << numeric_limits<int>::max() << endl;
	cout << "max(long): " << numeric_limits<long>::max() << endl;
	cout << endl;

	cout << "max(float): " << numeric_limits<float>::max() << endl;
	cout << "max(double): " << numeric_limits<double>::max() << endl;
	cout << "max(long double): " << numeric_limits<long double>::max() << endl;
	cout << endl;

	cout << "is_signed(char): " << numeric_limits<char>::is_signed << endl;
	// 判断string是否定义了数值极限，可以对任何类型进行查询包括类类型，
	// 无论它是否定义了极值
	cout << "is_specialized(string): " 
		<< numeric_limits<string>::is_specialized << endl;

	system("pause");
	return 0;
}