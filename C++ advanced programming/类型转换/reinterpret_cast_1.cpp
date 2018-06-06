#include <iostream>

int main()
{
	typedef int(*FunctionPointer)(int);
	int val = 21;
	FunctionPointer funcP;
	// 编译和链接都可以通过，但运行时会错误，
	// 因为funcP所指向的地址并不是函数入口地址
	// 只有将转换后的类型值转换回到其原始类型，这样才是正确使用reinterpret_cast方式
	funcP = reinterpret_cast<FunctionPointer>(&val);
	funcP(val);

	system("pause");
	return 0;
}