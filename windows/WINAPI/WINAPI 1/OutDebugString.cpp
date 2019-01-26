
#include <iostream>
#include <Windows.h>
#include <tchar.h>

using std::cout;
using std::endl;


void OutputDebugPrintfA(const char * strOutputString,...)
{
	char strBuffer[4096]={0};
	va_list vlArgs;
	va_start(vlArgs,strOutputString);
	_vsnprintf(strBuffer,sizeof(strBuffer)-1,strOutputString,vlArgs);
	//vsprintf(strBuffer,strOutputString,vlArgs);
	va_end(vlArgs);
	OutputDebugStringA(strBuffer);
}

int main()
{
	OutputDebugStringA("Debug information\n");
	OutputDebugStringW(_T("Debug information\n"));
	OutputDebugPrintfA("DEBUG_INFO | %d %s\n", 600019, "debug information");

	system("pause");
	return 0;
}