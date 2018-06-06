

// 编译器在a.f()处并不知道A<int>::f的定义，因为它不在test.h里面，
// 于是编译器只好寄希望于连接器，希望它能够在其他.obj里面找到
// A<int>::f的实例，在本例中就是test.obj，然而，后者中真有
// A<int>::f的二进制代码吗？NO！！！因为C++标准明确表示，
// 当一个模板不被用到的时侯它就不该被实例化出来，test.cpp中用到了
// A<int>::f了吗？没有！！所以实际上test.cpp编译出来的test.obj文件
// 中关于A::f一行二进制代码也没有，于是连接器就傻眼了，只好给出一个
// 连接错误。但是，如果在test.cpp中写一个函数，其中调用A<int>::f，
// 则编译器会将其实例化出来，因为在这个点上（test.cpp中），编译器
// 知道模板的定义，所以能够实例化，于是，test.obj的符号导出表中
// 就有了A<int>::f这个符号的地址，于是连接器就能够完成任务。

#include <iostream>
#include "test.h"

int main()
{
	A<int> a;
	a.f();

	system("pause");
	return 0;
}