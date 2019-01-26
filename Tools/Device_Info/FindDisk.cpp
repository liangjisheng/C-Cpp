
#include <iostream>
#include <Windows.h>

using namespace std;


// 遍历一个计算机上的所有盘符
BOOL GetDisk()
{
	DWORD dwDriveStrLen = 0;
	CHAR *pDriveName = NULL;
	UINT Drive  = 0;

	dwDriveStrLen = ::GetLogicalDriveStrings(0, NULL);			//取得计算机上盘符数目
	if (0 == dwDriveStrLen)
		return FALSE;

	CHAR *szDriveNameBuff = (CHAR*)malloc(dwDriveStrLen);		//根据你机器上的磁盘数目分配内存
	if (NULL == szDriveNameBuff)
		return FALSE;
	memset(szDriveNameBuff, 0, sizeof(szDriveNameBuff));

	::GetLogicalDriveStrings(dwDriveStrLen, szDriveNameBuff);	//取得你计算机上所有盘符

	pDriveName = szDriveNameBuff;
	while (*pDriveName != NULL)									//遍历所有盘符，找到你需要的设备
	{
		Drive = ::GetDriveType(pDriveName);
		switch (Drive)
		{
		case DRIVE_UNKNOWN:										//未知设备
			cout << pDriveName << endl;
			cout << "Unknow device" << endl;
			break;
		case DRIVE_NO_ROOT_DIR:
			cout << pDriveName << endl;
			cout << "not root dir" << endl;
			break;
		case DRIVE_REMOVABLE:									//usb设备
			cout << pDriveName << endl;
			cout << "usb device" << endl;
			break;
		case DRIVE_FIXED:										//硬盘
			cout << pDriveName << endl;
			cout << "hard disk" << endl;
			break;
		case DRIVE_REMOTE:										//网络硬盘,如：局域网服务器上的盘
			cout << pDriveName << endl;
			cout << "Internet disk" << endl;
			break;
		case DRIVE_CDROM:										//光驱
			cout << pDriveName << endl;
			cout << "cdRom" << endl;
			break;
		case DRIVE_RAMDISK:										//RAM 盘
			cout << pDriveName << endl;
			cout << "RAM disk" << endl;
			break;
		default:
			break;
		}
		pDriveName =  pDriveName + strlen(pDriveName) + 1;
	}   
	if (szDriveNameBuff != NULL)
	{
		free(szDriveNameBuff);
		szDriveNameBuff = NULL;
	}
	return TRUE;
}


int main()
{
	GetDisk();

	system("pause");
	return 0;
}

