
#include <stdio.h>

int main()
{
	// data的类型为int[2], 而&data的类型为int(*)[2]
	int data[2] = {0, 1};
	typedef int T[2];	// 此时T等同于int[2]类型
	T *pData;			// pData为指向int[2]数组类型的指针变量
	// pData指向具有2个元素的一维数组,分别为(*pData)[0]和(*pData)[1]
	pData = &data;		// 存储数组指针变量
	// 虽然data和&data的值相等，但他们的类型不一样，因此不能直接将
	// 数组变量名作为地址赋值给指向数组的指针变量
	// pData = data;			// error
	// pData + 1将前进8个字节
	printf("%d\n", (int)(pData + 1) - (int)pData);	// 8

	// *pData为指向的数组的第一个元素的地址,*pData与pData的值是相等的
	// 但类型不同,*pData是指向int型的指针
	printf("pData = 0x%x\n", pData);
	printf("*pData = 0x%x\n", *pData);

	printf("*pData + 1 = 0x%x\n", *pData + 1);

	getchar();
	return 0;
}