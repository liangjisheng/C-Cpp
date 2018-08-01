
// 判断一个操作系统是Windows还是Linux系统
// 可在编译阶段通过预定义宏判断

#include <iostream>

using std::cout;
using std::endl;

int main()
{
//#if defined (__linux__)
//	cout << "this is linux system" << endl;
//#elif defined (_WIN32 || _WIN64 || WIN32)
//	cout << "this is Windows system" << endl;
//#endif

#ifdef _WIN32 || _WIN64 || WIN32
	cout << "this is Windows system" << endl;
#elif defined __linux__
	cout << "this is linux system" << endl;
#endif

	system("pause");
	return 0;
}