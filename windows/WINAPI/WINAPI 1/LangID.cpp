
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <fstream>

using std::cout;
using std::endl;
using std::hex;
using std::dec;
using std::ofstream;

// GetSystemDefaultLangID和GetUserDefaultLangID获取的语言
// 受区域语言设置中的选项影响，所以这两个函数是不能用的
// 我们需要获取的是操作系统本身的语言版本
// GetSystemDefaultUILanguage的应用场景较单一
// 使用GetUserDefaultUILanguage应该是最有效的
ofstream g_ofs("langID_En.txt");
// ofstream g_ofs("langID_format_En.txt");
// ofstream g_ofs("langID_locale_En.txt");

void judge(LANGID wlangID)
{
	if(0x0804 == wlangID)
	{
		cout << wlangID << "\tChinese(PRC Sample)" << endl;
		g_ofs << wlangID << "\tChinese(PRC Sample)" << endl;
	}
	else if(0x0404 == wlangID)
	{
		cout << wlangID << "\tChinese(Taiwan Region)" << endl;
		g_ofs << wlangID << "\tChinese(Taiwan Region)" << endl;
	}
	else if(0x0c04 == wlangID)
	{
		cout << wlangID << "\tChinese(Hong Kong SAR,PRC)" << endl;
		g_ofs << wlangID << "\tChinese(Hong Kong SAR,PRC)" << endl;
	}
	else if(0x1004 == wlangID)
	{
		cout << wlangID << "\tChinese(Singapore)" << endl;
		g_ofs << wlangID << "\tChinese(Singapore)" << endl;
	}
	else if(0x0409 == wlangID)
	{
		cout << wlangID << "\tEnglish(United States)" << endl;
		g_ofs << wlangID << "\tEnglish(United States)" << endl;
	}
	else if(0x0809 == wlangID)
	{
		cout << wlangID << "\tEnglish(United Kingdom)" << endl;
		g_ofs << wlangID << "\tEnglish(United Kingdom)" << endl;
	}
}

int main()
{
	// GetSystemDefaultLangID可以判断当前系统是中文还是英文
	cout << "GetSystemDefaultLangID: ";
	g_ofs << "GetSystemDefaultLangID: ";
	LANGID langId = GetSystemDefaultLangID();
	judge(langId);
	g_ofs.flush();

	cout << endl;
	langId = 0x0000;
	langId = GetUserDefaultLangID();
	g_ofs << "GetUserDefaultLangID: ";
	cout << "GetUserDefaultLangID: ";
	judge(langId);
	g_ofs.flush();

	cout << endl;
	langId = 0x0000;
	langId = GetSystemDefaultUILanguage();
	g_ofs << "GetSystemDefaultUILanguage: ";
	cout << "GetSystemDefaultUILanguage: ";
	judge(langId);
	g_ofs.flush();

	cout << endl;
	langId = 0x0000;
	langId = GetUserDefaultUILanguage();
	g_ofs << "GetUserDefaultUILanguage: ";
	cout << "GetUserDefaultUILanguage: ";
	judge(langId);
	g_ofs.flush();
	

	g_ofs.close();
	system("pause");
	return 0;
}