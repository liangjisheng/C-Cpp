
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

//获取系统磁盘信息，包含系统磁盘序号、硬件ID
//系统磁盘序号由函数返回，硬件ID以参数的形式获取
//返回-1，代表函数失败。  
int GetSysDiskInfo(char *pDiskHardID, int nBufLen)  
{  
	vector<string> vecDisk;
	int nDiskOrder = -1;
	HANDLE hDevice = INVALID_HANDLE_VALUE;   
	DWORD nRealRead = 0;  

	STORAGE_DEVICE_NUMBER sdnDisk;							// 磁盘序列号 
	char sSystemDriveName[MAX_PATH];						//系统所在驱动器，一般为\\.\C:
	memset(&sdnDisk, 0, sizeof(STORAGE_DEVICE_NUMBER));  
	memset(sSystemDriveName, 0, sizeof(sSystemDriveName));  

	const char DiskEnumRegPath[] = "SYSTEM\\CurrentControlSet\\Services\\Disk\\Enum\\";  
	HKEY DiskEnumRegKey = NULL;  

	if (NULL == pDiskHardID || nBufLen < 0) 
		goto END;    

	//获取系统盘符  
	sprintf_s(sSystemDriveName, sizeof(sSystemDriveName), "\\\\.\\");
	GetSystemDirectory(sSystemDriveName + strlen(sSystemDriveName), 
		sizeof(sSystemDriveName) - strlen(sSystemDriveName));  
	cout << "System Directory: " << sSystemDriveName << endl;
	cout << endl;

	if (NULL == strchr(sSystemDriveName + strlen("\\\\.\\"), '\\'))    
		goto END;  
	*(strchr(sSystemDriveName + strlen("\\\\.\\"), '\\')) = 0;  

	
	vecDisk.push_back("\\\\.\\C:");
	vecDisk.push_back("\\\\.\\D:");
	vecDisk.push_back("\\\\.\\E:");

	for(int i = 0; i < vecDisk.size(); i++)
	{
		//获取系统磁盘序号  
		if ((hDevice = CreateFile(vecDisk[i].c_str(), GENERIC_READ | GENERIC_WRITE, 
			FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL)) == INVALID_HANDLE_VALUE  
			|| 0 == DeviceIoControl(hDevice, IOCTL_STORAGE_GET_DEVICE_NUMBER, NULL, 
			0, &sdnDisk, sizeof(sdnDisk), &nRealRead, NULL))  
		{  
			goto END;  
		}  
		else
		{
			cout << "Disk: " << vecDisk[i] << endl;
			cout << "Disk.DeviceNumber = " << sdnDisk.DeviceNumber << endl;
			cout << "Disk.DeviceType = " << sdnDisk.DeviceType << endl;
			cout << "Disk.PartitionNumber = " << sdnDisk.PartitionNumber << endl;
		}

		char szDiskNum[64] = {0};
		//memset(sSystemDriveName, 0, sizeof(sSystemDriveName));  
		itoa(sdnDisk.DeviceNumber, szDiskNum, 10);						//磁盘序号转换成字符串
		int nBufferLen = 1024;

		if (ERROR_SUCCESS != RegOpenKeyEx(HKEY_LOCAL_MACHINE, DiskEnumRegPath, 0, KEY_READ, &DiskEnumRegKey)  
			|| ERROR_SUCCESS != RegQueryValueEx(DiskEnumRegKey, szDiskNum, 
			NULL, NULL, (LPBYTE)pDiskHardID, (LPDWORD)&nBufferLen))  
		{  
			goto END;  
		} 
		else
			cout << "Disk HardWare ID: " << pDiskHardID << endl;

		hDevice = INVALID_HANDLE_VALUE;
		cout << endl;
	}

END: 

	if (hDevice != INVALID_HANDLE_VALUE)  
		CloseHandle(hDevice);   
	if (DiskEnumRegKey != NULL)    
		RegCloseKey(DiskEnumRegKey);   

	return nDiskOrder;  
}  


int main()
{
	char szHardWareID[1024] = {0};
	int nLenPath = 1024;
	int nDiskOrder = GetSysDiskInfo(szHardWareID ,1024);

	cout << szHardWareID << endl;

	system("pause");
	return 0;
}

