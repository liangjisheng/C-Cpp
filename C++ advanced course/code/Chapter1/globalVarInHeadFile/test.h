
// 一般而言，变量只能定义在.c文件中，声明变量才在.h文件中，下面就打破常规
// 在.h文件中定义变量，但是对实际而言，变量定义在头文件中只是表面的

#ifndef TEST_H
#define TEST_H

#ifdef TEST_CPP			// 该句宏一般放在相应的cpp文件中，宏只能定义一次
int myVar = 0;
#else
extern int myVar;		// 如果宏没定义，相当于在cpp文件中引用变量
#endif

extern void Print(void);

#endif