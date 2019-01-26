
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int no_os_flag = 1;

#ifdef linux
	no_os_flag = 0;
	cout << "this is Linux OS" << endl;
#endif

#ifdef _UNIX
	no_os_flag = 0;
	cout << "this is UNIX OS" << endl;
#endif

#ifdef _WINDOWS_
	no_os_flag = 0;
	cout << "this is Windows OS" << endl;
#endif

	// 如果程序的配置是Win32,那么只会输出this is WIN32 OS
	// 如果程序的配置是x64,那么会输出this is WIN32 OS和
	// this is WIN64 OS

#ifdef _WIN32
	no_os_flag = 0;
	cout << "this is WIN32 OS" << endl;
#endif

#ifdef _WIN64
	no_os_flag = 0;
	cout << "this is WIN64 OS" << endl;
#endif

	if(1 == no_os_flag)
		cout << "No OS Defined,I do not know what the os is" << endl;

	// system("systeminfo");
	system("ipconfig");
	system("pause");
	return 0;
}