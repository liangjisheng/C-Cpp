
#ifndef _GUID_TEST_HPP_
#define _GUID_TEST_HPP_

#include <string>
#include <iostream>
#include <Guiddef.h>

// 既可以使用GUID定义也可以使用UUID定义，在window下叫GUID，在Linux在叫UUID
//typedef struct _MyGUID
//{
//	unsigned long Data1;
//	unsigned short Data2;
//	unsigned short Data3;
//	unsigned char Data4[8];
//}MyGUID;

namespace Liangjisheng
{
	GUID CreateGuid();
	std::string GuidToString(const GUID &guid);
}

#endif // _GUID_TEST_HPP_