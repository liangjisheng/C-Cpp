
// 全局唯一标识符(GUID，Globally Unique Identifier)
// 在Windows 平台上，GUID 广泛应用于微软的产品中，用于标识如注册表项、类及接口标识、数据库、系统目录等对象
// GUID 的格式为“xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx”，
// 其中每个 x 是 0-9 或 a-f 范围内的一个4位十六进制数。
// 例如：6F9619FF-8B86-D011-B42D-00C04FC964FF 即为有效的 GUID 值。

#include <objbase.h>
#include <stdio.h>


const char* newGUID()
{
	static char buf[64] = {0};
	GUID guid;
	if (S_OK == ::CoCreateGuid(&guid))
	{
		_snprintf(buf, sizeof(buf)
			, "{%08X-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X}"
			, guid.Data1
			, guid.Data2
			, guid.Data3
			, guid.Data4[0], guid.Data4[1]
		, guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5]
		, guid.Data4[6], guid.Data4[7]
		);
	}
	return (const char*)buf;
}


int main(int argc, char* argv[])
{
	//--COM
	CoInitialize(NULL);
	printf(newGUID());
	printf("\n");
	//--COM
	CoUninitialize();

	int test = 12345;
	printf("0x%08x\n", test);

	getchar();
	return 0;
}