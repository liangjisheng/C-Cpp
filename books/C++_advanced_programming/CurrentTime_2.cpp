#include <Windows.h>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	LARGE_INTEGER t1, t2, tc;
	// ��ȡ�߾������м�������Ƶ��,��λ��ÿ����ٴ�(n/s),����һ��ܴ�
	QueryPerformanceFrequency(&tc);
	cout << "Frequency: " << tc.QuadPart << endl;
	QueryPerformanceCounter(&t1);
	Sleep(1000);
	QueryPerformanceCounter(&t2);

	cout << "Begin Time: " << t1.QuadPart << endl;
	cout << "End Time: " << t2.QuadPart << endl;
	cout << "Lasting Time: " << t2.QuadPart - t1.QuadPart << endl;
	cout << "Lasting Time: " << (t2.QuadPart - t1.QuadPart) / tc.QuadPart << endl;

	system("pause");
	return 0;
}