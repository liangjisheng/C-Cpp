
#include<iostream>
#include<windows.h>

using std::cout;
using std::endl;

int main()
{
	char* pSysDir = NULL;
	// 如果第二个参数不够大，则会返回需要的缓冲区长度包括最后的\0结束符
	int nReqLen = GetSystemDirectory(pSysDir, 0);
	pSysDir = new char[nReqLen];
	memset(pSysDir, 0, nReqLen);
	GetSystemDirectory(pSysDir, nReqLen);
	cout << pSysDir << endl;				// C:\Windows\System32

	char path[MAX_PATH] = {0};
	GetSystemDirectory(path, MAX_PATH);
	cout << path << endl;

	system("pause");
	return 0;
}