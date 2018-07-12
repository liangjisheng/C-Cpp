
// 在控制台下测试回车\r和换行\n

#include <stdio.h>
#include <Windows.h>

void test()
{
	printf("123\r100\n");		// 100
	printf("12345\r100\n");		// 10045

	printf("MoreWindows");
	printf("12345\r00\n");
}

void test1()
{
	char szText[] = "MoreWindows";
	printf("12345679\r");
	Sleep(2000);
	for (int i = 0; i < strlen(szText); ++i)
	{
		putchar(szText[i]);
		Sleep(200);
	}
	putchar('\n');
}

int main()
{
	test1();

	getchar();
	return 0;
}