
#define _DEBUG_TRACE_CMH_ 3

#if 0 != _DEBUG_TRACE_CMH_
	#include <cstdio>
#endif

#if 1 == _DEBUG_TRACE_CMH_			// 普通打印
	#define TRACE_CMH printf
#elif 2 == _DEBUG_TRACE_CMH_		// 打印文件名、行号
	#define TRACE_CMH(fmt, ...)\
		printf("%s(%d): "##fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#elif 3 == _DEBUG_TRACE_CMH_		// 打印文件名、行号、函数名
	#define TRACE_CMH(fmt, ...)\
		printf("%s(%d)-<%s>: "##fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#elif
	#define TRACE_CMH
#endif	// _DEBUG_TRACE_CMH_


class A
{
public:
	A() { TRACE_CMH("%d\n", 0); }
};


int main()
{
	A a;

	printf("%s\n", __DATE__);		// 在源文件中插入当前的编译日期
	printf("%s\n", __TIME__);		// 在源文件中插入当前编译时间
	// printf("%d\n", __STDC__);	// 当要求程序严格遵循ANSI C标准时该标识被赋值为1

	getchar();
	return 0;
}