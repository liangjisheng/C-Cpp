
// 获取一个机器上所有的设备信息
#include <stdio.h>
#include <windows.h>
#include <setupapi.h>
#include <devguid.h>
#include <regstr.h>
#include <cfgmgr32.h>
#include <iostream>
#include <tchar.h>
#include <fstream>
// #include <usbiodef.h>

using std::cout;
using std::wcout;
using std::endl;
using std::ofstream;

#pragma comment(lib, "Setupapi.lib")

int main( int argc, char *argv[ ], char *envp[ ] )
{
	HDEVINFO hDevInfo;
	SP_DEVINFO_DATA DeviceInfoData;

	// Create a HDEVINFO with all present devices.
	hDevInfo = SetupDiGetClassDevs(NULL,
		0, // Enumerator
		0,
		DIGCF_PRESENT | DIGCF_ALLCLASSES );

	if (hDevInfo == INVALID_HANDLE_VALUE)
		return 1;

	// Enumerate through all devices in Set.
	DeviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
	DWORD i;
	for(i = 0; SetupDiEnumDeviceInfo(hDevInfo, i, &DeviceInfoData); i++)
	{
		// printf("第%ld个设备实例\n", i);
		DWORD DataT;
		LPTSTR buffer = NULL;
		DWORD buffersize = 0;

		// Call function with null to begin with, 
		// then use the returned buffer size (doubled)
		// to Alloc the buffer. Keep calling until
		// success or an unknown failure.
		//
		//  Double the returned buffersize to correct
		//  for underlying legacy CM functions that 
		//  return an incorrect buffersize value on 
		//  DBCS/MBCS systems.
		// 
		while (!SetupDiGetDeviceRegistryProperty(
			hDevInfo,
			&DeviceInfoData,
			SPDRP_DEVICEDESC,
			&DataT,
			(PBYTE)buffer,
			buffersize,
			&buffersize))
		{
			if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
			{
				// Change the buffer size.
				if (buffer) 
				{
					LocalFree(buffer);
					buffer = NULL;
				}
				// Double the size to avoid problems on 
				// W2k MBCS systems per KB 888609. 
				buffer = (LPTSTR)LocalAlloc(LPTR, buffersize * 2);
			}
			else
			{
				// Insert error handling here.
				break;
			}
		}

		//LPTSTR szBuf = _T("test");
		//wcout << (LPWSTR)szBuf << endl;

		//ofstream out("device_info.txt", std::ios::out | std::ios::app);
		//out << buffer << endl;
		//out.close();

		//printf("Result:[%s]\n\n",buffer);
		cout << "Result_" << i << ":" << (LPTSTR)buffer << endl;

		if (buffer) 
		{
			LocalFree(buffer);
			buffer = NULL;
		}
	}


	if ( GetLastError() != NO_ERROR && GetLastError() != ERROR_NO_MORE_ITEMS )
	{
		// Insert error handling here.
		return 1;
	}

	//  Cleanup
	SetupDiDestroyDeviceInfoList(hDevInfo);

	// getchar();
	system("pause");
	return 0;
}

//通过MSDN的方法只能获取GUID跟设备名称的的值  我通过
	/*while (!SetupDiGetDeviceRegistryProperty(
		hDevInfo,
		&DeviceInfoData,
		SPDRP_DEVICEDESC,
		&DataT,
		(PBYTE)buffer,
		buffersize,
		&buffersize))*/
//替换掉SPDRP_DEVICEDESC  用去ID跟地址的关键字 都是不行的 怎么回事  求助更多 0