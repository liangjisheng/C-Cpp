// �ܾ�ȷ�����뼶��ȱ��ʹ����windows API
#include <Windows.h>
#include <stdio.h>

int main()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf("%4d/%02d/%02d\n %02d:%02d:%02d.%03d\n����%1d\n",
		sys.wYear, sys.wMonth, sys.wDay,
		sys.wHour, sys.wMinute, sys.wSecond,
		sys.wMilliseconds, sys.wDayOfWeek);

	getchar();
	return 0;
}