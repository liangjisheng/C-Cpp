#include"windows.h"
#include"iostream"
#include"cstring"
using namespace std;

int main() 
{
	HWND hwnd=NULL;
	OpenClipboard(hwnd); // 打开剪切板
	EmptyClipboard();	// 清空剪切板
	HANDLE hHandle=GlobalAlloc(GMEM_FIXED,1000);// 分配内存
	char* pData=(char*)GlobalLock(hHandle);
	strcpy(pData,"this is a ClipBoard Test.");
	SetClipboardData(CF_TEXT,hHandle);// 设置剪切板数据
	GlobalUnlock(hHandle);// 解除锁定
	CloseClipboard();	// 关闭剪切板

	OpenClipboard(hwnd);
	EmptyClipboard();
	if(IsClipboardFormatAvailable(CF_TEXT))
	{
		HANDLE h=GetClipboardData(CF_TEXT);
		char* p=(char*)GlobalLock(h);
		GlobalUnlock(h);
		CloseClipboard();
	}
	return 0;
}