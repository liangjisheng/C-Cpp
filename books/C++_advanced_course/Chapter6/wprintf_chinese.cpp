
#include <stdio.h>
#include <locale.h>

void test_1()
{
	printf("%s\n", "multibyte中文");
	printf("\n");
	// printf("%S\n", "multibyte中文");
	printf("%s\n", "multibyte中文");
	printf("\n");
	printf("%s\n", "unicode中文");
	printf("\n");
	// printf("%S\n", "unicode中文");
	printf("%s\n", "unicode中文");
	printf("\n");

	// 默认情况下wprintf()是不能输出中文的，需要将C语言的全局locale设置
	// 为本地语言(C语言中只有全局locale)
	setlocale(LC_CTYPE, "");

	wprintf(L"%s\n", L"multibyte中文");
	printf("\n");
	// wprintf(L"%S\n", L"multibyte中文");
	wprintf(L"%s\n", L"multibyte中文");
	printf("\n");
	wprintf(L"%s\n", L"unicode中文");
	printf("\n");
	// wprintf(L"%S\n", L"unicode中文");
	wprintf(L"%s\n", L"unicode中文");

	setlocale(LC_CTYPE, "C");		// 回复原来默认的C语言设置
}


int main()
{
	test_1();

	getchar();
	return 0;
}