#include <iostream>
#include <string.h>
#include <afx.h>
#include <tchar.h>
#include <Windows.h>
using namespace std;

int main()
{
	char buf[5];
	CString str;
	CString str1;
	CString str2;
	memset(buf, 0, sizeof(buf));
	for(int i = 0; i < 5; i++)
	{
		str.Format(_T("%d"), buf[i]);
		str1 += str;
	}
	str2.Format(_T("%d"), str1);
	cout << str2 << endl;
	//str2 = _T("asdf");
	cout << str2.GetBuffer() << endl;
	str2.ReleaseBuffer();
	cout << (LPTSTR)(LPCTSTR)str2 << endl;
	wcout << str2 << endl;

	cout << str2.GetString() << endl;
	wcout << str2.GetString() << endl;

	system("pause");
	return 0;
}