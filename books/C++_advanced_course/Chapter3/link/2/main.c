
#include <stdio.h>

// 不能直接包含Invokecpp.h,因为C语言不支持extern "C"声明，在.c文件中包含了
// extern "C"是就会出现编译错误，应该直接进行函数原型声明
void show();

int main()
{
	show();

	getchar();
	return 0;
}