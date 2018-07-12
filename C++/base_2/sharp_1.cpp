
#include <stdio.h>
#include <string.h>

#define F abc
#define B def
#define FB(arg) #arg
#define FB1(arg) FB(arg)

// 咋看的话，可能FB和FB1输出的结果是一样的，但实际上FB(F B)和FB1(F B)的结果是不一样的
// 单个#称为字符串化操作，#的主要作用是将宏参数不经扩展的转换成字符串常量，宏定义参数的
// 左右两边的空格会被忽略，参数的各个Token直接的多个空格会被转换成一个空格，宏定义
// 参数中含有需要特殊含义字符如"或\时，他们前面会自动被加上转义字符\

// 两个##称为标记连接操作,是将多个Token连接成一个Token，他不能是宏定义中的第一个或者
// 最后一个Token,前后的空格可有可无
#define paster(n) (printf_s("token" #n " = %d", token##n))

// 这个整型变量的名字必须为token9,如果想要写成其它名字,下面的paster()中的参数应该换成
// 相应的数字
int token9 = 9;


// 连接符#@：它将单字符标记符变换为单字符，即加单引号。例如：
#define B(x) #@x
// 则B(a)即'a'，B(1)即'1'，但B(abc)却不甚有效。


int main()
{
	const char *p1 = "hello," "world";		// 一个空格
	const char *p2 = "hello,"   "world";	// 多个空格
	const char *p3 = "hello,""world";		// 没有空格
	const char *p4 = "hello,world";			// 一个整串
	const char *p5 = "asdf,""asdfgh";		// 一个不同的串

	// p1,p2,p3,p4输出时是一样的
	printf("p1 = %s, strlen(p1) = %d\n", p1, strlen(p1));
	printf("p2 = %s, strlen(p2) = %d\n", p2, strlen(p2));
	printf("p3 = %s, strlen(p3) = %d\n", p3, strlen(p3));
	printf("p4 = %s, strlen(p4) = %d\n", p4, strlen(p4));
	printf("p5 = %s, strlen(p5) = %d\n", p5, strlen(p5));

	printf("\n");
	// 变换过程应该是FB(F B) -> #F B -> "F B"
	printf("FB(F B) = %s\n", FB(F B));
	// 变换过程应该是FB1(F B) -> FB1(abc def) -> FB(abc def) -> #abc def -> "abc def"
	printf("FB1(F B) = %s\n", FB1(F B));

	// 预处理步骤应该如下:
	paster(9);
	// printf_s("token" #9 " = %d", token##9);
	// printf_s("token" "9" " = %d", token9);
	// printf_s("token9 = %d", token9);

	getchar();
	return 0;
}
