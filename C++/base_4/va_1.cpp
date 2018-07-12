
// main函数也是被其它函数调用的，这个函数就是mainCRTStartup()
// 所以main()函数也有一个栈帧，即运行是堆栈，用esp,ebp维护

// 可变参数的理解
// 注意：可变参数必须从头到尾按照顺序逐个访问，但也可以在访问
// 几个参数之后半途中止。但是，不能从中间开始访问。此外，
// 由于参数列表中的可变参数部分并没有原型，所以，所有作为可变
// 参数传递给函数的值都将执行缺省参数类型提升。

#include <stdio.h>
#include <stdlib.h>		// for system()
#include <stdarg.h>
#include <string.h>
#include <assert.h>


// 第一个参数表明可变参数列表的参数总个数
void var_test(int i, ...)
{
	int j1 = 0;
	int j2 = 0;
	int j3 = 0;
	int j4 = 0;

	// 访问参数列表中的为确定部分
	va_list arg_ptr;			
	printf("i = %d\n", i);
	printf("&i = %p\n", &i);

	// 第二个参数是省略号前最后一个有名字的参数
	// va_start宏将arg_ptr设置为指向可变参数部分的第一个参数
	va_start(arg_ptr, i);
	printf("after va_start: arg_ptr = %p\n", arg_ptr);
	j1 = *((int*)arg_ptr);		// 获取arg_ptr指针指向的值
	printf("j1 = %d\n", j1);

	// va_arg用于访问参数，第二个参数是参数列表中下一个参数的类型
	// 在有些函数中，参数类型都是一样的，但有些函数可能要通过前面
	// 获得的数据来判断下一个参数的类型，例如printf检查格式化字符串
	// 中的字符来判断它需要打印的参数的类型，va_arg返回这个参数的值
	// 并使得arg_ptr变量指向下一个可变参数，如果此时已经是最后一个
	// 参数，则指向NULL
	j2 = va_arg(arg_ptr, int);
	printf("after va_arg: arg_ptr = %p\n", arg_ptr);
	printf("j2 = %d\n", j2);

	j3 = va_arg(arg_ptr, int);
	printf("after va_arg: arg_ptr = %p\n", arg_ptr);
	printf("j3 = %d\n", j3);

	j4 = va_arg(arg_ptr, int);
	printf("after va_arg: arg_ptr = %p\n", arg_ptr);
	printf("j4 = %d\n", j4);

	// 将arg_ptr置空
	va_end(arg_ptr);
	printf("after va_end: arg_ptr = %p\n", arg_ptr);
}


// 求平均数,i表示可变参数总的个数
float average(int i, ...)
{
	va_list arg_ptr;
	float sum = 0.0;

	va_start(arg_ptr, i);
	for(int j = 0; j < i; j++)
		sum += va_arg(arg_ptr, int);

	return sum / i;
}


// 简单实现printf函数
int my_printf(char* str, ...)
{
	assert(str);
	va_list arg_ptr;
	va_start(arg_ptr, str);

	int count = 0;
	const char* first = str;
	while(*first)
	{
		if(*first == '%')
		{
			first++;
			switch(*first)
			{
			case 'c':
				{
					char ch = va_arg(arg_ptr, char);
					putchar(ch);
					count++;
				}
				break;
			case 'd':
				{
					int n = va_arg(arg_ptr, int);
					char buf[10] = {0};
					_itoa(n, buf, 10);
					fputs(buf, stdout);
					count += strlen(buf);
				}
				break;
			case 's':
				{
					char *str = va_arg(arg_ptr, char*);
					fputs(str, stdout);
					count += strlen(str);
				}
				break;
			case 'f':
				{
					double f = va_arg(arg_ptr, double);
					// 第二个参数使用float会出现错误，float在x86的机器上占4字节，
					// 而double占8个字节，会显示错误，导致后面的参数也会读取错误
					// double f = va_arg(arg_ptr, float);
					char buf1[20] = {0};
					// sprintf(buf1, "%f", f);
					// 如果一个缓冲区的尺寸为digits的尺寸+1,该函数覆盖该缓冲区的末尾。
					// 这是因为转换的字符串包括一个小数点以及可能包含符号和指数信息。
					// 不提供上溢出。gcvt试图以十进制格式产生digits数字,如果不可能,
					// 它以指数格式产生digits数字,在转换时可能截除尾部的0。
					_gcvt(f, 15, buf1);		
					fputs(buf1, stdout);
					count += strlen(buf1);
				}
				break;
			default:
				break;
			}
			first++;
		}
		putchar(*first);
		first++;
		count++;
	}

	va_end(arg_ptr);
	return count;
}


int main()
{
	var_test(2, 4, 5);
	printf("\n\n");

	float f = average(5, 1, 2, 3, 4, 5);
	printf("%f\n", f);
	printf("\n\n");

	int ret = my_printf("hello %s, n = %d, f = %f, ch = %c", 
		"world", 11, 1.2345678, 'a');
	my_printf("\ncount = %d\n", ret);

	system("pause");
	return 0;
}


