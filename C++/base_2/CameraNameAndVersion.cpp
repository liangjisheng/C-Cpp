
// 获取当前机器上连接的摄像头的名称和版本信息

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include "vfw.h"

using std::cout;
using std::endl;

#pragma comment( lib, "vfw32.lib" )

void main()
{
	char strDeviceVersion[80];				//设备版本信息
	char strDeviceAndVersion[300];			//设备名和版本信息
	int nIndex;
	int nDriverCount = 0;					//支持的设备驱动程序个数
	for(nIndex=0; nIndex <9; nIndex++) 
	{ 
		if(capGetDriverDescriptionA(nIndex,
			(LPSTR)strDeviceAndVersion,
			sizeof(strDeviceAndVersion),
			(LPSTR)strDeviceVersion,
			sizeof(strDeviceVersion))) 
		{ 
			strcat(strDeviceAndVersion, ","); 
			strcat(strDeviceAndVersion, strDeviceVersion);
			cout << strDeviceAndVersion << endl;
			nDriverCount++;									//得到vfw设备信息及连的设备数量
		} 
		else
			break; 
	} 

	//if (nDriverCount == 0)
	//	cout <<"没有摄像头"<<endl; 
	//else
	//{
	//	cout <<"有摄像头"<<endl; 
	//	cout << strDeviceAndVersion << endl;		//输出设备名称
	//	cout << nDriverCount << endl;				//输出设备数量
	//}
}
