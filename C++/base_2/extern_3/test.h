
//综合使用
// 一般我们都将函数声明放在头文件，当我们的函数有可能被C或C++使用时，
// 我们无法确定是否要将函数声明在extern "C"里，所以，我们应该添加
//#ifdef __cplusplus
	//extern "C"
//{
//#endif
	//函数声明
//#ifdef __cplusplus
//}
//#endif


#ifdef __cplusplus
#include <iostream>
using namespace std;
extern "C"
{
#else
#include <stdio.h>
#endif

// 这样可以将mytest()的实现放在.c或者.cpp文件中
void mytest();

#ifdef __cplusplus
}
#endif
