#include"stdio.h"
#pragma comment(lib,"1224.lib")
extern int _declspec(dllimport) dllGlobalVar;

int main()
{
	printf("%d\n",dllGlobalVar);
	dllGlobalVar=1;
	printf("%d\n",dllGlobalVar);

	getchar();
	return 0;
}