
#include <iostream>
#include <string>
#include <Windows.h>

#pragma warning(disable: 4996)	// avoid GetVersionEx to be warned

// global macros
static const int kMaxInfoBuffer = 256;
#define GBYTES (1024 * 1024 * 1024)
#define MBYTES (1024 * 1024)
#define KBYTES (1024)
#define DKBYTES (1024.0)

using namespace std;

/**
 * function: 获取操作系统的名称和版本
 * param:
 * return: 
*/
void getOsInfo()
{
	// get os name according to version number
	OSVERSIONINFO osver = { sizeof(OSVERSIONINFO) };
	GetVersionEx(&osver);
	string os_name;

	if (osver.dwMajorVersion == 5 && osver.dwMinorVersion == 0)
		os_name = "Windows 2000";
	else if (osver.dwMajorVersion == 5 && osver.dwMinorVersion == 1)
		os_name = "Windows XP";
	else if (osver.dwMajorVersion == 5 && osver.dwMinorVersion == 2)
		os_name = "Windows vista";
	else if (osver.dwMajorVersion == 6 && osver.dwMinorVersion == 0)
		os_name = "Windows 2003";
	else if (osver.dwMajorVersion == 6 && osver.dwMinorVersion == 1)
		os_name = "Windows 7";
	else if (osver.dwMajorVersion == 6 && osver.dwMinorVersion == 2)
		os_name = "Windows 10";

	cout << "os name: " << os_name << endl;
	cout << "os version: " << osver.dwMajorVersion << "." << osver.dwMinorVersion << endl;
}


// save 4 register variables
DWORD deax;
DWORD debx;
DWORD decx;
DWORD dedx;

/**
 * function: init cpu in assembly language
 * param: veax: 索引为0(第一个)寄存器
 * return: 
*/
void initCpu(DWORD veax)
{
	__asm
	{
		mov eax, veax
		cpuid
			mov deax, eax
			mov debx, ebx
			mov decx, ecx
			mov dedx, edx
	}
}

/**
 * function: 获取CPU频率
 * param:
 * return: 返回CPU频率
*/
long getCpuFreq()
{
	int start, over;
	_asm
	{
		RDTSC
		mov start, eax
	}	
	Sleep(50);
	_asm
	{
		RDTSC
		mov over, eax
	}

	return (over - start) / 50000;
}

/**
 * function: 获取CPU的特定ID
 * param:
 * return: 返回ID字符串
*/
string getManufactureID()
{
	char manuID[25] = {0};
	
	initCpu(0);
	memcpy(manuID + 0, &debx, 4);	// copy to array
	memcpy(manuID + 4, &dedx, 4);
	memcpy(manuID + 8, &decx, 4);

	return manuID;
}

/**
 * function: 获取CPU类型
 * param:
 * return: 返回CPU类型的字符串
*/
string getCpuType()
{
	const DWORD id = 0x80000002;	// start 0x80000002 end to 0x80000004
	char cpuType[49] = {0};

	for (DWORD t = 0; t < 3; ++t)
	{
		initCpu(id + t);
		memcpy(cpuType + 16 * t + 0, &deax, 4);
		memcpy(cpuType + 16 * t + 4, &debx, 4);
		memcpy(cpuType + 16 * t + 8, &decx, 4);
		memcpy(cpuType + 16 * t + 12, &dedx, 4);
	}

	return cpuType;
}

void getCpuInfo()
{
	cout << "CPU main frequency: " << getCpuFreq() << "MHz" << endl;
	cout << "CPU manufacture: " << getManufactureID() << endl;
	cout << "CPU type: " << getCpuType() << endl;
}

/**
 * function: 获取内存信息
 * param:
 * return: 
*/
void getMemoryInfo()
{
	string memory_info;
	MEMORYSTATUSEX statusex;
	statusex.dwLength = sizeof(statusex);

	if (GlobalMemoryStatusEx(&statusex))
	{
		unsigned long long total = 0, remain_total = 0, avl = 0, remain_avl = 0;
		double decimal_total = 0, decimal_avl = 0;
		remain_total = statusex.ullTotalPhys % GBYTES;
		total = statusex.ullTotalPhys / GBYTES;
		avl = statusex.ullAvailPhys / GBYTES;
		remain_avl = statusex.ullAvailPhys % GBYTES;

		if (remain_total > 0)
			decimal_total = (remain_total / MBYTES) / DKBYTES;
		if (remain_avl > 0)
			decimal_avl = (remain_avl / MBYTES) / DKBYTES;

		decimal_total += (double)total;
		decimal_avl += (double)avl;

		char buffer[kMaxInfoBuffer] = {0};
		sprintf_s(buffer, kMaxInfoBuffer, "total %.2f GB (%.2f GB available)",
			decimal_total, decimal_avl);
		memory_info.append(buffer);
	}

	cout << memory_info << endl;
}


int main()
{
	cout << "===os information===" << endl;
	getOsInfo();

	cout << "===cpu infromation===" << endl;
	getCpuInfo();

	cout << "===memory information===" << endl;
	getMemoryInfo();

	system("pause");
	return 0;
}