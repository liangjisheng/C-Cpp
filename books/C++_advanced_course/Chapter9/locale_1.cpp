
// 有效的locale名称是"C",和任何预定义的locale."C"表示没过英语的ASCII
// 码locale,是在非国际化程序中使用的默认方式.用空字符串表示的locale名称""
// 则表示系统选择的本国习俗,它与当前的设置有关

#include <iostream>
#include <locale>

using namespace std;

// 合法名称是在系统源文件中getqloc.c中定义的

int main()
{
	locale native("");		// 本地locale
	locale usa("American_USA.1252");		// 美国
	locale Holland("Dutch");
	locale global;			// 全局locale
	cout << "native: " << native.name() << endl;
	cout << "classic: " << locale::classic().name() << endl;	// 当前全局locale
	cout << "global: " << global.name() << endl;
	cout << "Holland: " << Holland.name() << endl;
	cout << "usa: " << usa.name() << endl;

	system("pause");
	return 0;
}