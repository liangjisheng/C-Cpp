
#include <stdio.h>
#include <locale.h>

void test_1()
{
	printf("%s\n", "multibyte����");
	printf("\n");
	// printf("%S\n", "multibyte����");
	printf("%s\n", "multibyte����");
	printf("\n");
	printf("%s\n", "unicode����");
	printf("\n");
	// printf("%S\n", "unicode����");
	printf("%s\n", "unicode����");
	printf("\n");

	// Ĭ�������wprintf()�ǲ���������ĵģ���Ҫ��C���Ե�ȫ��locale����
	// Ϊ��������(C������ֻ��ȫ��locale)
	setlocale(LC_CTYPE, "");

	wprintf(L"%s\n", L"multibyte����");
	printf("\n");
	// wprintf(L"%S\n", L"multibyte����");
	wprintf(L"%s\n", L"multibyte����");
	printf("\n");
	wprintf(L"%s\n", L"unicode����");
	printf("\n");
	// wprintf(L"%S\n", L"unicode����");
	wprintf(L"%s\n", L"unicode����");

	setlocale(LC_CTYPE, "C");		// �ظ�ԭ��Ĭ�ϵ�C��������
}


int main()
{
	test_1();

	getchar();
	return 0;
}