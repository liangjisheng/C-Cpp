#include"stdio.h"
#include"..\\1095.h"	// 类声明
#pragma comment(lib,"..\\Debug\\1095.lib")
int __declspec(dllimport) nMy1095;
int __declspec(dllimport) fnMy1095();
class __declspec(dllimport) CMy1095;

int main()
{
	printf("nMy1095=%d\n",nMy1095);
	printf("fnMy1095=%d\n",fnMy1095());
	CMy1095 A;
	A.print();
	getchar();
	return 0;
}