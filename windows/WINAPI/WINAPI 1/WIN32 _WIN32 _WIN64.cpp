
// VC有3个预处理常量，分别是_WIN32,_WIN64,WIN32
// Win32配置下，WIN32在项目属性-C/C++预处理器-预处理器定义里面声明
// 而在x64配置下，这个常量并不在项目预定义列表中

// 只要包含了Windows.h，那么WIN32常量是肯定定义了的，所以不能用来
// 判断平台环境

// _WIN32和_WIN64没有任何显式定义。在 Windows.h 里没有，在“项目属性】
// -C/C++-预处理器-预处理器定义”下也没有。根据 MSDN，这是由编译器
// (ml.exe/ml64.exe)内部定义的

#include <iostream>

using namespace std;

int main()
{
#ifdef _WIN64
	cout << "_WIN64 is defined as " << _WIN64 << endl;
#endif

#ifdef _WIN32
	cout << "_WIN32 is defined as " << _WIN32 << endl;
#endif

	system("pause");
	return 0;
}