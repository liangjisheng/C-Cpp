
// GetACP()可以获取当前系统的代码页编码，如简体中文是936
// 如果获得Dos下的代码页，则需要调用GetOEMCP()函数
// 如果要判断代码页的有效性，调用 IsValidCodePage 函数

#include <Windows.h>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	UINT nCodePage = GetACP();
	cout << nCodePage << endl;
	nCodePage = 0;
	nCodePage = GetOEMCP();
	cout << nCodePage << endl;

	system("pause");
	return 0;
}