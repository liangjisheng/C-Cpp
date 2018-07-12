
// 分层设计就是将软件分层具有某种上下级关系的模块，由于每一层都是相对独立的
// 因此只要定义好层与层之间的接口，从而每层都可以单独实现。
// 上层可以直接调用下层提供的函数，但下层不能直接调用上层提供的函数，且层与层
// 之间绝对不能循环调用，因为层与层之间的循环依赖会严重妨碍软件的复用性和可扩展
// 性，是的系统中的每一层都无法独立构成一个可复用的组件。上层只能调用相邻下层
// 提供的函数，不能跨层调用。即下层模块实现了在上层模块中声明并被高层模块调用
// 的接口，这就是著名的好莱坞扩展原则：不要调用我，让我调用你。当下层需要传递
// 数据给上层时，则采用回调函数指针接口隔离变化

// 由上层模块(即调用者)提供的回调函数的表现形式就是在下层模块中通过函数指针调用
// 另一个函数，即将回调函数的地址作为实参初始化下层模块的形参，由下层模块在某个
// 时刻调用这个函数，这个函数就是回调函数

#include <stdio.h>
#include <string.h>
#include "bubbleSort.h"

int compare_int(const void * e1, const void * e2)
{ return *(int*)e1 - *(int*)e2; }

int compare_int_r(const void * e1, const void * e2)
{ return *(int*)e2 - *(int*)e1; }

// 因为bubbleSort传递的类型是char**的数组元素的地址&array[i],而不是类型为char*的array[i]
int compare_str(const void * e1, const void * e2)
{ return strcmp(*(char**)e1, *(char**)e2); }


int main()
{
	int arrayInt[] = {39, 33, 18, 64, 73, 30, 49, 51, 81};
	int numArray = sizeof(arrayInt) / sizeof(arrayInt[0]);
	bubbleSort(arrayInt, numArray, sizeof(arrayInt[0]), compare_int);
	for(int i = 0; i < numArray; i++)
		printf("%d ", arrayInt[i]);
	printf("\n");

	bubbleSort(arrayInt, numArray, sizeof(arrayInt[0]), compare_int_r);
	for(int i = 0; i < numArray; i++)
		printf("%d ", arrayInt[i]);
	printf("\n");

	char * arrayStr[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	numArray = sizeof(arrayStr) / sizeof(arrayStr[0]);
	bubbleSort(arrayStr, numArray, sizeof(arrayStr[0]), compare_str);
	for(int i = 0; i < numArray; i++)
		printf("%s\n", arrayStr[i]);
	// printf("\n");

	getchar();
	return 0;
}