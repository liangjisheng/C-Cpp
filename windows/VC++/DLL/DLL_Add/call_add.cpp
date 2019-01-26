#include"stdio.h"
#include"windows.h"
typedef int(*lpAddFun)(int,int);

int main()
{
	HINSTANCE hDll;		// DLL句柄
	lpAddFun addFun;
	hDll=LoadLibrary("..\\Debug\\1073.dll");
	if(hDll!=NULL) {
		addFun=(lpAddFun)GetProcAddress(hDll,"add");
		if(addFun!=NULL) {
			int result=addFun(2,3);
			printf("%d\n",result);
		}
	}
	FreeLibrary(hDll);
	return 0;
}