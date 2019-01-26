
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

int findNstPositon(char *str, char c, int n);


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
		TCHAR szHWID[] = _T("USB\\VID_0828&PID_1002&REV_0000");
		TCHAR szHWDes[] = _T("Wintone Passport Reader");

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
			// SPDRP_DEVICEDESC,						// 获取设备描述
			SPDRP_HARDWAREID,						// 硬件id
			// SPDRP_CLASSGUID,							// GUID
			//SPDRP_COMPATIBLEIDS,
			&DataT,
			(PBYTE)buffer,
			buffersize,
			&buffersize))
		{
			int nError = GetLastError();
			if (nError == ERROR_INSUFFICIENT_BUFFER)
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
			else if(nError == ERROR_INVALID_DATA)
			{
				break;
			}
			else
			{
				// Insert error handling here.
				break;
			}
		}

		if(buffer)
		{
			int nIndex = findNstPositon(buffer, '&', 2);
			buffer[nIndex] = '\0';
		/*	if(_tcscmp(buffer, szHWID) == 0)
			{				
				int a = 0;
				int b = 0;
			}

			if(_tcscmp(buffer, szHWDes) == 0)
			{
				int a = 0;
				int b = 0;
			}*/
			cout << "Result_" << i << ":" << buffer << endl;

			ofstream out("device_info.txt", std::ios::out | std::ios::app);
			out << buffer << endl;
			out.close();			
		}

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


/************************************************************************/
/* 查找某个字符在字符串中第n次出现的位置                                */
/************************************************************************/
int findNstPositon(char *str, char c, int n)  
{  
	if(!str || c == '\0')
		return -1;
	
	char *p = str;  
	int index = 0;  
	int count = 0;  

	while(*p != '\0')  
	{  
		if(*p == c)  
			count ++;  
		if(count < n)  
		{
			p++;  
			index++;  
		}
		else  
			break;
	}
	return index;  

}  
