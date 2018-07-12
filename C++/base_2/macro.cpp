
#include <stdio.h>

// 查看一个变量的地址和值
#define PRINT_INT(i)\
	printf("%8s():&%-5s = 0x%-6x, %-5s = 0x%-6x\n", __FUNCTION__, #i, &(i), #i, i)

#define PRINT_PTR(p)\
	printf("%8s():&%-5s = 0x%-6x, %-5s = 0x%-6x, *%-5s = 0x%-6x\n", \
		__FUNCTION__, #p, &(p), #p, p, #p, *p)


void test_print_int()
{
	int iNum1, iNum2, temp;
	printf("input two numbers:");
	scanf("%x%x", &iNum1, &iNum2);
	PRINT_INT(iNum1);
	PRINT_INT(iNum2);
	temp = iNum1;
	iNum1 = iNum2;
	iNum2 = temp;
	PRINT_INT(iNum1);
	PRINT_INT(iNum2);
}

void test_print_ptr()
{
	int iNum = 0x64;
	int *ptr = NULL;

	PRINT_INT(iNum);
	ptr = &iNum;
	PRINT_PTR(ptr);
}


int main()
{
	// test_print_ptr();

	// %p和%x一样都是输出16进制，%p会将数字显示为16进制大写
	printf("0x%p\n", 1024);
	printf("0x%x\n", 1024);
	printf("0x%p\n", 1023);
	printf("0x%x\n", 1023);

	getchar();
	getchar();
	return 0;
}