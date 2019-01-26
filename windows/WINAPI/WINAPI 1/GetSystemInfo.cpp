
// 获取系统信息
#include <iostream>
#include <windows.h>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

void test()
{
	SYSTEM_INFO systemInfo;
	GetSystemInfo(&systemInfo);
	cout << setw(20) << "处理器掩码: " << systemInfo.dwActiveProcessorMask << endl
		<< setw(20) << "处理器架构: " << systemInfo.wProcessorArchitecture << endl
		<< setw(20) << "处理器个数: " << systemInfo.dwNumberOfProcessors << endl
		<< setw(20) << "处理器分页大小: " << systemInfo.dwPageSize << endl
		<< setw(20) << "处理器类型: " << systemInfo.dwProcessorType << endl
		<< setw(20) << "处理器级别: " << systemInfo.wProcessorLevel << endl
		<< setw(20) << "虚拟内存分配粒度: " << systemInfo.dwAllocationGranularity << endl
		<< setw(20) << "最大寻址单元: " << systemInfo.lpMaximumApplicationAddress << endl
		<< setw(20) << "最小寻址单元: " << systemInfo.lpMinimumApplicationAddress << endl
		<< setw(20) << "处理器等级: " << systemInfo.wProcessorLevel << endl
		<< setw(20) << "处理器版本: " << systemInfo.wProcessorRevision << endl;
}

typedef INT_PTR (*MYFARPROC)(SYSTEM_INFO* lpSystemInfo);

void test_1()
{
	SYSTEM_INFO systemInfo;
	HINSTANCE handle;
	MYFARPROC func;

	handle = LoadLibraryA("kernel32.dll");
	if(handle)
	{
		func = (MYFARPROC)GetProcAddress(handle, "GetNativeSystemInfo");
		if(func)
			func(&systemInfo);					// Runtime error
		else
			GetSystemInfo(&systemInfo);
		FreeLibrary(handle);
	}
	else
		GetSystemInfo(&systemInfo);

	switch(systemInfo.wProcessorArchitecture)
	{
	case PROCESSOR_ARCHITECTURE_AMD64:							// x64(AMD or Intel)
		cout << "cpu Architecture : x64" << endl;
		break;
	case PROCESSOR_ARCHITECTURE_ARM:							// ARM
		cout << "cpu Architecture : arm" << endl;
		break;
	case PROCESSOR_ARCHITECTURE_IA64:
		cout << "cpu Architecture : Intel Itanium-based" << endl;
		break;
	case PROCESSOR_ARCHITECTURE_INTEL:
		cout << "cpu Architecture : x86" << endl;
		break;
	case PROCESSOR_ARCHITECTURE_UNKNOWN:
		cout << "cpu Architecture : unknown\n" << endl;
		break;
	}
}

int main()
{
	test();
	cout << endl;

	test_1();
	cout << endl;

	system("pause");
	return 0;
}