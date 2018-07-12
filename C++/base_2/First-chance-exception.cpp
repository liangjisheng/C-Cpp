
#include <iostream>
#include <Windows.h>
#include <tchar.h>

using std::cout;
using std::endl;

int main()
{
	try{
		throw(100);
	}catch(int n){
		cout << "catch n = " << n << endl;
	}
	OutputDebugString(_T("test\r\n"));

	system("pause");
	return 0;
}