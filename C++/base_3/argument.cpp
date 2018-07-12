
// 可变参数
#include <stdio.h>
#include <stdarg.h>

void Stdarg(int a1, ...)
{
	va_list argp;					// 指向参数的指针
	int arr[5];
	va_start(argp, a1);				// 用va_start()宏初始化变量argp,
	arr[0] = a1;
	for(int i = 1; i < 5; i++)
		// va_arg返回可变的参数，第二个参数是你要返回的参数的类型，这里是int型
		arr[i] = va_arg(argp, int);	
	va_end(argp);					// va_end()宏结束可变参数的获取

	for(int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


void simple_va_fun(int i, ...)
{
	va_list arg_ptr;
	int j = 0;

	va_start(arg_ptr, i);
	j = va_arg(arg_ptr, int);
	va_end(arg_ptr);

	printf("%d %d\n", i, j);
	return ;
}


int main()
{
	// Stdarg(1, 2, 3, 4, 5);

	simple_va_fun(100);
	simple_va_fun(100, 200);
	simple_va_fun(100, 200, 300);

	getchar();
	return 0;
}

