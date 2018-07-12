
#include <iostream>
#include <stdio.h>
#include <locale.h>

using std::cout;
using std::endl;
using std::wcout;

void test_1()
{
	// _wsetlocale(),setlocale()设置宽字符和多字节的本地化环境
	_wsetlocale(LC_ALL, L"chs");
	wprintf(L"%s\n", L"测试");

	wprintf(L"%s\n", L"test");

	printf("%s\n", "测试");
	printf("%s\n", "test");
}

void test_2()
{
	wcout.imbue(std::locale("chs", std::locale::all));
	cout << "test" << endl;
	wcout << L"test" << endl;
	cout << "测试" << endl;
	wcout << L"测试" << endl;
}


int main()
{
	test_2();
	printf("\n");

	wchar_t w_text[] = L"asdf";
	printf("%ls\n", w_text);
	
	system("pause");
	return 0;
}

