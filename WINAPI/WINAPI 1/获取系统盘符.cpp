// GetLogicalDirveStrings 用于获取系统盘符
// 返回盘符信息 C:\\0D:\\0E:\\0F:\\0G:\\0H:\\0J:\\0
#include"iostream"
#include"string.h"
#include"windows.h"
using namespace std;

int main(int argc,char * argv[])
{
	DWORD dwLen=GetLogicalDriveStrings(0,NULL);	// 获取系统盘符字符串长度
	char *pszDriver=new char[dwLen];
	GetLogicalDriveStrings(dwLen,pszDriver);	// 获取系统盘符字符串
	char *pDriver=pszDriver;
	while(*pDriver!='\0') {
		cout<<pDriver<<endl;
		pDriver+=strlen(pDriver)+1;		// 加1是为了跳过\0字符
	}
	delete []pszDriver;
	system("pause");
	return 0;
}