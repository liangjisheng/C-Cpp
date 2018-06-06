
#include <iostream>
#include <string>
#include <locale>
#include <Windows.h>

using namespace std;

void test()
{
	wchar_t *str = L"ABC我们";
	// 强制转化后,字符串数据并没有发生任何变化,只是用多字节字符编码重新
	// 对它进行解释,只会输出一个A
	char *s = (char*)str;
	cout << s << endl;
}

// 标准C++库实现字符编码转换
// 如果第二个参数为空,函数返回当前的locale设置，否则依据输入的两个参数设置新
// 的locale,设置成功返回一个描述新的locale的字符串，否则返回一个空指针
// char* setlocale(int category, const char *locale);

// pReturnValue指向转换后的字符串长度，sizeOfmbchar是多字节字符串所可能拥有的
// 最大长度,mbstate是一个指向状态字的指针
// errno_t wcstombs_s(size_t *pReturnValue, char *mbchar, size_t sizeOfmbchar,
//						wchar_t *wchar, mbstate_t *mbstate);
// mbstowcs_s()

string ws2s(const wstring &ws)
{
	size_t convertedChars = 0;
	string curLocale = setlocale(LC_ALL, NULL);		// curLocale = "C"
	setlocale(LC_ALL, "chs");
	const wchar_t *_source = ws.c_str();
	size_t _Dsize = 2 * ws.size() + 1;
	char *_Dest = new char[_Dsize];
	wcstombs_s(&convertedChars, _Dest, _Dsize, _source, _TRUNCATE);
	string result = _Dest;
	delete []_Dest;
	_Dest = NULL;
	setlocale(LC_ALL, curLocale.c_str());
	return result;
}

wstring s2ws(const string &s)
{
	size_t convertedChars = 0;
	setlocale(LC_ALL, "chs");
	const char *_Sourct = s.c_str();
	size_t _Dsize = s.size() + 1;
	wchar_t *_Dest = new wchar_t[_Dsize];
	mbstowcs_s(&convertedChars, _Dest, _Dsize, _Sourct, _TRUNCATE);
	wstring result = _Dest;
	delete []_Dest;
	_Dest = NULL;
	setlocale(LC_ALL, "C");
	return result;
}

void test_ws_s()
{
	wchar_t *wstr = L"ABC我们";
	string obj(ws2s(wstr));
	cout << obj << endl;
	char *str = "ABC我们";
	wstring wobj(s2ws(str));
	std::wcout.imbue(std::locale("chs"));
	wcout << wobj << endl;
}

void test_ws_s_WINAPI()
{
	wchar_t *ws = L"测试字符串";
	char *ss = "ABC我们";
	int BufSize = 0;
	// 第一个参数是CP_UTF8是将宽字符转换成UTF8,此时最后两个参数必须设为NULL
	// 第二个参数dwFlags指定如何处理没有转换的字符，一般设为0
	// -1表示转换到字符串结尾
	// cbMultiByte,即第5个参数，如果为0，则第四个参数将被忽略，函数返回所需
	// 缓冲区的大小
	BufSize = WideCharToMultiByte(CP_ACP, 0, ws, -1, NULL, 0, NULL, FALSE);
	cout << BufSize << endl;
	char *sp = new char[BufSize];
	WideCharToMultiByte(CP_ACP, 0, ws, -1, sp, BufSize, NULL, FALSE);
	cout << sp << endl;
	delete [] sp;
	sp = NULL;

	BufSize = MultiByteToWideChar(CP_ACP, 0, ss, -1, NULL, 0);
	cout << BufSize << endl;
	wchar_t *wp = new wchar_t[BufSize];
	MultiByteToWideChar(CP_ACP, 0, ss, -1, wp, BufSize);
	std::wcout.imbue(std::locale("chs"));
	std::wcout << wp << endl;
	delete [] wp;
	wp = NULL;
}

int main()
{
	// test_ws_s();
	test_ws_s_WINAPI();

	system("pause");
	return 0;
}