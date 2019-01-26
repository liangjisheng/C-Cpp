
#include "CLog.h"
//#include <iostream>

//using std::cout;

void test_log()
{
	CLog log1(1);
	CLog log2(1.1);
	CLog log3(1.2);
	CLog log4('a');				// 如果只是一个字符的话，会走int类型的构造函数
	CLog log5("a");
	CLog log6("test");
}

int main()
{
	test_log();
	{
		CLog log1("test");
	}
	{
		CLog log2(5);
	}
	{
		CLog log1(3.4);
	}

	system("pause");
	return 0;
}

