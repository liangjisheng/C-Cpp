
// 操作系统和内存信息在windows下通过系统API来获取,CPU信息则需要通底层CPUID指令取得

#include <iostream>
#include <string>
#include <Windows.h>

using std::string;
using std::cout;
using std::endl;

#pragma warning(disable: 4996)	// avoid GetVersionEx to be warned

// global macros
static const int kMaxInfoBuffer = 256;
#define GBYTES	1073741824
#define MBYTES	1048576
#define KBYTES	1024
#define DKBYTES	1024.0

// get os info
void getOsInfo()
{
	// get os name according to version number
	OSVERSIONINFO osver = { sizeof(OSVERSIONINFO) };
	GetVersionEx(&osver);
	cout << "dwBuildNumber: " << osver.dwBuildNumber << endl;
	cout << "dwMajorVersion: " << osver.dwMajorVersion << endl;
	cout << "dwMinorVersion: " << osver.dwMinorVersion << endl;
	cout << "dwOSVersionInfoSize: " << osver.dwOSVersionInfoSize << endl;
	cout << "dwPlatformId: " << osver.dwPlatformId << endl;
	cout << "szCSDVersion: " << osver.szCSDVersion << endl;
	cout << endl;

	string os_name;
	if(osver.dwMajorVersion == 5 && osver.dwMinorVersion == 0)
		os_name = "Windows 2000";
	else if(osver.dwMajorVersion == 5 && osver.dwMinorVersion == 1)
		os_name = "Windows XP";
	else if(osver.dwMajorVersion == 6 && osver.dwMinorVersion == 0)
		os_name = "Windows 2003";
	else if(osver.dwMajorVersion == 5 && osver.dwMinorVersion == 2)
		os_name = "Windows vista";
	else if(osver.dwMajorVersion == 6 && osver.dwMinorVersion == 1)
		os_name = "Windows 7";
	else if(osver.dwMajorVersion == 6 && osver.dwMinorVersion == 2)
		os_name = "Windows 10";

	cout << "os name: " << os_name << endl;
	cout << "os version: " << osver.dwMajorVersion << '.' 
		<< osver.dwMinorVersion << endl;
}

// get memory info
void getMemoryInfo()
{
	string memory_info;
	MEMORYSTATUSEX statusex;
	statusex.dwLength = sizeof(statusex);
	if(GlobalMemoryStatusEx(&statusex))
	{
		cout << "statusex.dwLength: "					<< statusex.dwLength				<< endl;
		cout << "statusex.dwMemoryLoad: "				<< statusex.dwMemoryLoad			<< endl;
		cout << "statusex.ullAvailExtendedVirtual: "	<< statusex.ullAvailExtendedVirtual << endl;
		cout << "statusex.ullAvailPageFile: "			<< statusex.ullAvailPageFile		<< endl;
		cout << "statusex.ullAvailPhys: "				<< statusex.ullAvailPhys			<< endl;
		cout << "statusex.ullAvailVirtual: "			<< statusex.ullAvailVirtual			<< endl;
		cout << "statusex.ullTotalPageFile: "			<< statusex.ullTotalPageFile		<< endl;
		cout << "statusex.ullTotalPhys: "				<< statusex.ullTotalPhys			<< endl;
		cout << "statusex.ullTotalVirtual: "			<< statusex.ullTotalVirtual			<< endl;

		unsigned long long total  = 0, remain_total = 0, avl = 0, remain_avl = 0;
		double decimal_total = 0, decimal_avl = 0;
		remain_total = statusex.ullTotalPhys % GBYTES;
		total = statusex.ullTotalPhys / GBYTES;
		avl = statusex.ullAvailPhys / GBYTES;
		remain_avl = statusex.ullAvailPhys % GBYTES;

		if(remain_total > 0)
			decimal_total = (remain_total / MBYTES) / DKBYTES;
		if(remain_avl > 0)
			decimal_avl = (remain_avl / MBYTES) / DKBYTES;

		decimal_total += (double)total;
		decimal_avl += (double)avl;
		char buffer[kMaxInfoBuffer] = {0};
		cout << "total " << decimal_total << "GB" << endl;
		cout << "available " << decimal_avl << "GB" << endl;
		sprintf_s(buffer, kMaxInfoBuffer, "total %.2f GB(%.2f GB available)",
			decimal_total, decimal_avl);

		memory_info.append(buffer);
	}

	cout << memory_info << endl;
}

// get cpu info
// save 4 register variables
DWORD deax;
DWORD debx;
DWORD decx;
DWORD dedx;

// init cpu in assembly language
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

string getManufactureID()
{
	char manuID[25] = {0};
	initCpu(0);
	memcpy(manuID + 0, &debx, 4);
	memcpy(manuID + 4, &dedx, 4);
	memcpy(manuID + 7, &decx, 4);

	return manuID;
}

string getCpuType()
{
	// start 0x80000002 end to 0x80000004
	const DWORD id = 0x80000002;
	char cpuType[49] = {0};
	
	for(DWORD t = 0; t < 3; t++)
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
	cout << "CPU main frequency: " << getCpuFreq() << "MHZ" << endl;
	cout << "CPU manufacture: " << getManufactureID() << endl;
	cout << "CPU type: " << getCpuType() << endl;
}


int main()
{
	// getOsInfo();
	// getMemoryInfo();
	getCpuInfo();

	system("pause");
	return 0;
}