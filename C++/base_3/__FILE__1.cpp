
#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;

// 由于第一个宏TRACE_CMH_1调用了两次printf，所以效率没有第二个宏高
#define TRACE_CMH_1 (printf("%s(%d)-<%s>: ", __FILE__,  __LINE__, __FUNCTION__), printf)

#define TRACE_CMH_2(fmt, ...) \
	printf("%s(%d)-<%s>: " ##fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

int nCount = 1;

class CBase
{
public:
	CBase() { TRACE_CMH_2("BASE: [%d]\n", nCount++); }
};

class CSub : public CBase
{
public:
	CSub() { TRACE_CMH_1("SUB: [%d]\n", nCount++); }
};


int main()
{
	CSub sub;

	system("pause");
	return 0;
}

