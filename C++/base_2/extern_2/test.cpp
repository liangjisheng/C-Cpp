
// 在C中引用C++文件

#include <stdio.h>

// 编译时默认以C约定命名
extern "C" 
{
void mytest() { printf("mytest in .cpp file ok\n"); }
}