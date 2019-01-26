#include"stdio.h"
#pragma comment(lib,"..\\Debug\\1074.lib")
extern int _declspec(dllimport) n;
int _declspec(dllimport) fnMy1074(void);
class _declspec(dllimport) CMy1074;

int main()
{
	printf("%d\n",n);
	n=2;
	printf("%d\n",n);
	fnMy1074();
	CMy1074 A();
	return 0;
}