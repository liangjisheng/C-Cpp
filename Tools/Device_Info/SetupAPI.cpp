
// 这个程序主要是通过SetupAPI和DDK中的CM_XX函数族对设备进行枚举、状态查询和控制
// 下面先是对使用的SetupAPI函数的说明，然后是程序代码，该程序其实可以禁用任何可以被禁用的设备，
// 只不过我没有去做罢了，运行第一次会将USB Mass Storage设备都禁用，第二次会将它们都启用
// 请使用DDK编译。或者在VC中使用driverstdio将环境设为DDK环境编译

// SetupDiGetClassDevs如果第二个参数设为NULL,第四个参数为DIGCF_ALLCLASSES，则返回所有设备信息。

// SetupDiGetClassImageList建立一个包含所有已经安装的类位图的映像列表并返回含有这个列表的数据结
//typedef struct _SP_CLASSIMAGE_DATA 
//{
	//DWORD  cbSize;
	//HIMAGELIST  ImageList;
	//DWORD  Reserved;
//} SP_CLASSIMAGE_DATA, *PSP_CLASSIMAGE_DATA;

// SetupDiEnumDeviceInfo为一个设备的设备信息集单元返回上下文结构：SP_DEVINFO_DATA
//typedef struct _SP_DEVINFO_DATA 
//{
	//DWORD  cbSize;
	//GUID   ClassGuid;
	//DWORD  DevInst;
	//ULONG_PTR  Reserved;
//} SP_DEVINFO_DATA, *PSP_DEVINFO_DATA;

// CM_Get_DevNode_Status用来获得设备实例的状态

// SetupDiOpenClassRegKey打开设备类的主键或者指定类的子键

// SetupDiGetDeviceRegistryProperty获得指定的即插即用的设备属性

// SetupDiGetClassImageIndex获得指定设备在设备映像列表中的索引

// SetupDiGetDeviceInstallParams获得指定设备的安装信息

// SetupDiSetClassInstallParams为设备信息集或者
// 是一个实际的设备信息单元设置或清除类安装参数,需要传入SP_PROPCHANGE_PARAMS结构指针，
// 这个结构是负责协调DIF_PROPERTYCHANGE 安装请求

// SetupDiCallClassInstaller根据DIF代码调用安装服务

#include <stdio.h>
#include <malloc.h>
#include <tchar.h>
#include <string.h>
#include <windows.h>
#include <setupapi.h>
#include <cfgmgr32.h>
#include <regstr.h>
// #include "common.h"

#define UnknownDevice TEXT("<Unknown Device>")
#define USBDISK      TEXT("Mass")


typedef struct _DEVICE_INFO										//设备信息结构链表
{
	SP_DEVINFO_DATA  WY_DevInfoData;							//设备信息包括实例句柄 和设备类的GUID
	DWORD     WY_DevID;											//在此次全局的枚举中设备ID
	TCHAR     *WY_lpszDevName;									//设备的名称
	ULONG     WY_ulDevNameLen;									//设备名称的长度
	BOOL      WY_isDisableable;									//是否可以被禁用
	BOOL      WY_isDisabled;										//是否已经被禁用
	struct _DEVICE_INFO        *WY_pNextDevInfo;				//下一个结构块
}WY_DEVICE_INFO,*WY_pDEVICE_INFO;

TCHAR WY_tcDebugStr[1024];										//输出的调试信息

//StateChange函数用来改变设备的状态，可以设为启用或者禁用
BOOL StateChange(DWORD WY_dwNewState, DWORD WY_dwDevID, HDEVINFO WY_hDevInfo);

//EnumDevice函数用来枚举计算机中所包含的所有设备
BOOL EnumDevices(HWND WY_hDevInfo);

//GetRegistryProperty函数用来获得设备注册表中的内容
BOOL GetRegistryProperty(HDEVINFO WY_hDevInfo, PSP_DEVINFO_DATA WY_DevInfoData, 
	ULONG WY_ulProperty, PVOID WY_pBuffer,PULONG WY_pulBufLen);

//ConstructDeviceName函数用来构造设备名称
BOOL  ConstructDeviceName( HDEVINFO  DeviceInfoSet, PSP_DEVINFO_DATA DeviceInfoData,
	PVOID Buffer, PULONG  Length);

//EnableDevice函数用来启用设备
BOOL EnableDevice(DWORD WY_dwDevID,HDEVINFO WY_hDevInfo);

//DisableDevice函数用来禁止设备
BOOL DisableDevice(DWORD WY_dwDevID,HDEVINFO WY_hDevInfo);

//查询该设备是否可以被禁用
BOOL IsDisableable (DWORD WY_dwDevID, HDEVINFO WY_hDevInfo);

//查询该设备是否已经禁用
BOOL  IsDisabled (DWORD WY_dwDevID, HDEVINFO WY_hDevInfo);

//GUID结构复制函数，
//因为sdk的函数的头文件不知道为什么不能在DDK的环境下使用，只好自己写
void  GuidCopy(GUID WY_guidSrc,GUID *WY_guidDest);

//控制USB设备
BOOL ControlDevice(DWORD WY_dwDevID,HDEVINFO WY_hDevInfo);


WY_DEVICE_INFO WY_DevInfo;									//设备链表头

int APIENTRY WinMain(HINSTANCE WY_hInstance,HINSTANCE WY_hPreInstance,LPSTR WY_lpCmd,int WY_nCmdNum)
{
	HDEVINFO   WY_hDevInfo;
	WY_pDEVICE_INFO WY_pDevInfo;

	WY_hDevInfo = SetupDiGetClassDevs(NULL, NULL, NULL, DIGCF_PRESENT | DIGCF_ALLCLASSES);
	_stprintf(WY_tcDebugStr,"WY_hDevInfo %x", WY_hDevInfo);
	OutputDebugString(WY_tcDebugStr);

	WY_DevInfo.WY_DevInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
	WY_DevInfo.WY_ulDevNameLen = 256;
	WY_DevInfo.WY_pNextDevInfo = NULL;

	EnumDevices((HWND)WY_hDevInfo);
	WY_pDevInfo = WY_DevInfo.WY_pNextDevInfo;

	while(WY_pDevInfo)					//从系统设备中查找usb mass storage设备
	{					
		_stprintf(WY_tcDebugStr,
			"DevID : %d GUID:%x-%x-%x-%x%x%x%x%x%x%x%x DevInst : %x,DevName:%s IsDisableable:%d, IsDisabled:%d"
			,WY_pDevInfo->WY_DevID
			,WY_pDevInfo->WY_DevInfoData.ClassGuid.Data1
			,WY_pDevInfo->WY_DevInfoData.ClassGuid.Data2
			,WY_pDevInfo->WY_DevInfoData.ClassGuid.Data3
			,WY_pDevInfo->WY_DevInfoData.ClassGuid.Data4[0]
			,WY_pDevInfo->WY_DevInfoData.ClassGuid.Data4[1]
			,WY_pDevInfo->WY_DevInfoData.ClassGuid.Data4[2]
			,WY_pDevInfo->WY_DevInfoData.ClassGuid.Data4[3]
			,WY_pDevInfo->WY_DevInfoData.ClassGuid.Data4[4]
			,WY_pDevInfo->WY_DevInfoData.ClassGuid.Data4[5]
			,WY_pDevInfo->WY_DevInfoData.ClassGuid.Data4[6]
			,WY_pDevInfo->WY_DevInfoData.ClassGuid.Data4[7]
			,WY_pDevInfo->WY_DevInfoData.DevInst
			,WY_pDevInfo->WY_lpszDevName
			,WY_pDevInfo->WY_isDisableable
			,WY_pDevInfo->WY_isDisabled);

		OutputDebugString(WY_tcDebugStr);

		if(strstr(WY_pDevInfo->WY_lpszDevName,USBDISK))
		{
			//控制usb mass storage 设备的状态，如果启用则禁用，如果仅用则启用
			if(ControlDevice(WY_pDevInfo->WY_DevID, WY_hDevInfo))
				OutputDebugString("Successful");
			else
				OutputDebugString("FAILED");
		}
		WY_pDevInfo = WY_pDevInfo->WY_pNextDevInfo;
	}

	SetupDiDestroyDeviceInfoList(WY_hDevInfo);
	return 0;
}


BOOL StateChange(DWORD WY_dwNewState, DWORD WY_dwDevID, HDEVINFO WY_hDevInfo)
{
	SP_PROPCHANGE_PARAMS  WY_PropChangeParams;
	SP_DEVINFO_DATA   WY_DevInfoData = {sizeof(SP_DEVINFO_DATA)};
	SP_DEVINSTALL_PARAMS  WY_devParams;

	//查询设备信息
	if(!SetupDiEnumDeviceInfo(WY_hDevInfo, WY_dwDevID, &WY_DevInfoData))
	{
		OutputDebugString("SetupDiEnumDeviceInfo FAILED");
		return FALSE;
	}

	//设置设备属性变化参数
	WY_PropChangeParams.ClassInstallHeader.cbSize = sizeof(SP_CLASSINSTALL_HEADER);
	WY_PropChangeParams.ClassInstallHeader.InstallFunction = DIF_PROPERTYCHANGE;
	WY_PropChangeParams.Scope = DICS_FLAG_GLOBAL;  //使修改的属性保存在所有的硬件属性文件
	WY_PropChangeParams.StateChange = WY_dwNewState;
	WY_PropChangeParams.HwProfile = 0;

	//改变设备属性
	if(!SetupDiSetClassInstallParams(WY_hDevInfo, &WY_DevInfoData,
		(SP_CLASSINSTALL_HEADER *)&WY_PropChangeParams, sizeof(WY_PropChangeParams)))
	{
		OutputDebugString("SetupDiSetClassInstallParams FAILED");
		return FALSE;
	}

	WY_PropChangeParams.ClassInstallHeader.cbSize = sizeof(SP_CLASSINSTALL_HEADER);
	WY_PropChangeParams.ClassInstallHeader.InstallFunction = DIF_PROPERTYCHANGE;
	WY_PropChangeParams.Scope = DICS_FLAG_CONFIGSPECIFIC;//使修改的属性保存在指定的属性文件
	WY_PropChangeParams.StateChange = WY_dwNewState;
	WY_PropChangeParams.HwProfile = 0;

	//改变设备属性并调用安装服务
	if(!SetupDiSetClassInstallParams(WY_hDevInfo, &WY_DevInfoData,
		(SP_CLASSINSTALL_HEADER *)&WY_PropChangeParams, sizeof(WY_PropChangeParams))
		|| !SetupDiCallClassInstaller(DIF_PROPERTYCHANGE, WY_hDevInfo, &WY_DevInfoData))
	{
		OutputDebugString("SetupDiSetClassInstallParams or SetupDiCallClassInstaller FAILED");
		return TRUE;
	}
	else
	{	//判断是否需要重新启动
		WY_devParams.cbSize = sizeof(WY_devParams);
		if(!SetupDiGetDeviceInstallParams(WY_hDevInfo, &WY_DevInfoData, &WY_devParams))
		{
			OutputDebugString("SetupDiGetDeviceInstallParams FAILED");
			return FALSE;
		}
		if(!WY_devParams.Flags & (DI_NEEDRESTART | DI_NEEDREBOOT))
		{
			OutputDebugString("Need Restart Computer");
			return TRUE;
		}
		return TRUE;
	}
}


BOOL EnumDevices(HWND WY_hDevInfo)
{
	DWORD     WY_dwDevID,WY_dwStatus,WY_dwProblem;
	SP_DEVINFO_DATA  WY_DevInfoData = {sizeof(SP_DEVINFO_DATA)};
	WY_pDEVICE_INFO  WY_pDevInfo,WY_ppreDevInfo;
	TCHAR         *WY_DeviceName;
	ULONG     WY_ulNameLen = 256;
	WY_ppreDevInfo = &WY_DevInfo;

	//穷举每个设备
	for(WY_dwDevID = 0; SetupDiEnumDeviceInfo(WY_hDevInfo, WY_dwDevID, &WY_DevInfoData); WY_dwDevID++)
	{
		//构造设备信息块
		WY_pDevInfo = (WY_pDEVICE_INFO)malloc(sizeof(WY_DEVICE_INFO));
		WY_pDevInfo->WY_pNextDevInfo = NULL;
		WY_pDevInfo->WY_DevInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
		WY_pDevInfo->WY_ulDevNameLen;
		WY_pDevInfo->WY_DevID = WY_dwDevID;
		GuidCopy(WY_DevInfoData.ClassGuid,&WY_pDevInfo->WY_DevInfoData.ClassGuid);
		WY_pDevInfo->WY_DevInfoData.DevInst = WY_DevInfoData.DevInst;
		WY_pDevInfo->WY_DevInfoData.Reserved = WY_DevInfoData.Reserved;

		//这里有个问题，如果用设备信息块结构中的字符串指针
		//SetupDiGetDeviceRegistyProperty函数就会返回数据无效，不知道为什么。
		//所以下面只能在重新复制一遍了。
		ConstructDeviceName(WY_hDevInfo,&WY_DevInfoData,&WY_DeviceName,&WY_ulNameLen);
		WY_pDevInfo->WY_ulDevNameLen = WY_ulNameLen;
		WY_pDevInfo->WY_lpszDevName = (TCHAR *)malloc(WY_ulNameLen*sizeof(TCHAR));
		memcpy(WY_pDevInfo->WY_lpszDevName,WY_DeviceName,WY_ulNameLen);
		WY_pDevInfo->WY_isDisableable = IsDisableable(WY_dwDevID, WY_hDevInfo);
		WY_pDevInfo->WY_isDisabled = IsDisabled(WY_dwDevID, WY_hDevInfo);
		WY_ppreDevInfo->WY_pNextDevInfo = WY_pDevInfo;
		WY_ppreDevInfo = WY_pDevInfo;
	}
	return FALSE;
}


BOOL GetRegistryProperty(HDEVINFO WY_hDevInfo, PSP_DEVINFO_DATA WY_DevInfoData, 
	ULONG WY_ulProperty, PVOID WY_pBuffer, PULONG WY_pulBufLen)
{
	//读取设备的注册表信息
	while (!SetupDiGetDeviceRegistryProperty(WY_hDevInfo,
		WY_DevInfoData,
		WY_ulProperty,  //信息字段
		NULL,
		(PBYTE)*(TCHAR **)WY_pBuffer,
		*WY_pulBufLen,
		WY_pulBufLen
		))
	{
		if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
		{ 
			//如果长度不够则重新分配缓冲区
			if (*(LPTSTR *)WY_pBuffer)
				LocalFree(*(LPTSTR *)WY_pBuffer);
			*(LPTSTR *)WY_pBuffer = (LPTSTR)LocalAlloc(LPTR,*WY_pulBufLen);
		}
		else
		{
			if (GetLastError() != ERROR_INVALID_DATA)
				OutputDebugString(TEXT("GetDeviceRegistryProperty"));
			return FALSE;
		}           
	}
	return (*(LPTSTR *)WY_pBuffer)[0];
}


BOOL ConstructDeviceName(HDEVINFO WY_DevInfoSet, PSP_DEVINFO_DATA WY_DevInfoData, PVOID WY_pBuffer, PULONG Length)
{
	//尝试通过各种类型的设备描述获得其设备名称
	if (!GetRegistryProperty(WY_DevInfoSet,
		WY_DevInfoData,
		SPDRP_FRIENDLYNAME ,//设备的现实名称
		WY_pBuffer,
		Length))
	{
		if (!GetRegistryProperty(WY_DevInfoSet,
			WY_DevInfoData,
			SPDRP_DEVICEDESC ,//设备的描述
			WY_pBuffer,
			Length))
		{
			if (!GetRegistryProperty(WY_DevInfoSet,
				WY_DevInfoData,
				SPDRP_CLASS ,//设备类名
				WY_pBuffer,
				Length))
			{
				if (!GetRegistryProperty(WY_DevInfoSet,
					WY_DevInfoData,
					SPDRP_CLASSGUID ,//设备的GUID
					WY_pBuffer,
					Length))
				{//什么都没找到就返回UnknownDevice
					*Length = (_tcslen(UnknownDevice)+1)*sizeof(TCHAR);
					*(LPTSTR *)WY_pBuffer = (LPTSTR)LocalAlloc(LPTR,*Length);
					_tcscpy(*(LPTSTR *)WY_pBuffer,UnknownDevice);
				}
			}
		}
	}
	return TRUE;
}


BOOL EnableDevice(DWORD WY_dwDevID, HDEVINFO WY_hDevInfo)
{
	return StateChange(DICS_ENABLE,WY_dwDevID,WY_hDevInfo);
}


BOOL DisableDevice(DWORD WY_dwDevID, HDEVINFO WY_hDevInfo)
{
	return StateChange(DICS_DISABLE,WY_dwDevID,WY_hDevInfo);
}


BOOL IsDisableable(DWORD WY_dwDevID, HDEVINFO WY_hDevInfo)
{
	SP_DEVINFO_DATA WY_DevInfoData = {sizeof(SP_DEVINFO_DATA)};
	DWORD    WY_dwDevStatus,WY_dwProblem;
	if(!SetupDiEnumDeviceInfo(WY_hDevInfo, WY_dwDevID, &WY_DevInfoData))
	{
		OutputDebugString("SetupDiEnumDeviceInfo FAILED");
		return FALSE;
	}
	//查询设备状态
	if(CM_Get_DevNode_Status(&WY_dwDevStatus,&WY_dwProblem,WY_DevInfoData.DevInst,0)!=CR_SUCCESS)
	{
		OutputDebugString("CM_GET_DevNode_Status FAILED");
		return FALSE;
	}
	return ((WY_dwDevStatus & DN_DISABLEABLE) && (WY_dwProblem != CM_PROB_HARDWARE_DISABLED));
}


BOOL IsDisabled(DWORD WY_dwDevID, HDEVINFO WY_hDevInfo)
{
	SP_DEVINFO_DATA WY_DevInfoData = {sizeof(SP_DEVINFO_DATA)};
	DWORD    WY_dwDevStatus,WY_dwProblem;
	if(!SetupDiEnumDeviceInfo(WY_hDevInfo, WY_dwDevID, &WY_DevInfoData))
	{
		OutputDebugString("SetupDiEnumDeviceInfo FAILED");
		return FALSE;
	}
	//查询设备状态
	if(CM_Get_DevNode_Status(&WY_dwDevStatus, &WY_dwProblem, WY_DevInfoData.DevInst, 0)!=CR_SUCCESS)
	{
		OutputDebugString("CM_GET_DevNode_Status FAILED");
		return FALSE;
	}
	return ((WY_dwDevStatus & DN_HAS_PROBLEM) && (WY_dwProblem == CM_PROB_DISABLED));
}


void GuidCopy(GUID WY_guidSrc, GUID *WY_guidDest)
{
	WY_guidDest->Data1 = WY_guidSrc.Data1;
	WY_guidDest->Data2 = WY_guidSrc.Data2;
	WY_guidDest->Data3 = WY_guidSrc.Data3;
	memcpy(WY_guidDest->Data4, WY_guidSrc.Data4, 8);
}


BOOL ControlDevice(DWORD WY_dwDevID, HDEVINFO WY_hDevInfo)
{
	BOOL WY_isCanDisable;
	WY_isCanDisable = (IsDisableable(WY_dwDevID, WY_hDevInfo) && (!IsDisabled(WY_dwDevID, WY_hDevInfo)));
	if(WY_isCanDisable)
		return DisableDevice(WY_dwDevID, WY_hDevInfo);
	else
		return EnableDevice(WY_dwDevID, WY_hDevInfo);
}

