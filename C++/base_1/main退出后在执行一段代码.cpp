// 需要执行一段在main退出后执行的代码,使用atexit()注册一个函数
#include"stdio.h"
#include"stdlib.h"
#include"iostream"

int atexit(void (*function)(void));
void fn1(void), fn2(void), fn3(void), fn4(void);

int main()
{
	atexit(fn1);
	atexit(fn2);
	atexit(fn3);
	atexit(fn4);
	printf("This is executed first.\n");
	printf("退出main.在执行一段代码\n");
	system("pause");
	return 0;
}

void fn1()
{ printf("next.\n"); }

void fn2()
{ printf("executed "); }

void fn3()
{ printf("is "); }

void fn4()
{ printf("This "); }
