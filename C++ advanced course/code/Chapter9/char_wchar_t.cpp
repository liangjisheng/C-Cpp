
#include <iostream>
#include <string>
#include <locale>
#include <Windows.h>

using namespace std;

void test()
{
	wchar_t *str = L"ABC����";
	// ǿ��ת����,�ַ������ݲ�û�з����κα仯,ֻ���ö��ֽ��ַ���������
	// �������н���,ֻ�����һ��A
	char *s = (char*)str;
	cout << s << endl;
}

// ��׼C++��ʵ���ַ�����ת��
// ����ڶ�������Ϊ��,�������ص�ǰ��locale���ã����������������������������
// ��locale,���óɹ�����һ�������µ�locale���ַ��������򷵻�һ����ָ��
// char* setlocale(int category, const char *locale);

// pReturnValueָ��ת������ַ������ȣ�sizeOfmbchar�Ƕ��ֽ��ַ���������ӵ�е�
// ��󳤶�,mbstate��һ��ָ��״̬�ֵ�ָ��
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
	wchar_t *wstr = L"ABC����";
	string obj(ws2s(wstr));
	cout << obj << endl;
	char *str = "ABC����";
	wstring wobj(s2ws(str));
	std::wcout.imbue(std::locale("chs"));
	wcout << wobj << endl;
}

void test_ws_s_WINAPI()
{
	wchar_t *ws = L"�����ַ���";
	char *ss = "ABC����";
	int BufSize = 0;
	// ��һ��������CP_UTF8�ǽ����ַ�ת����UTF8,��ʱ�����������������ΪNULL
	// �ڶ�������dwFlagsָ����δ���û��ת�����ַ���һ����Ϊ0
	// -1��ʾת�����ַ�����β
	// cbMultiByte,����5�����������Ϊ0������ĸ������������ԣ�������������
	// �������Ĵ�С
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