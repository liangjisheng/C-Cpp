
// C++支持重载，而C不支持重载，由于这个原因，全局变量或函数被C++编译后在
// 符号库中的名字与C语言不同
// 编译器在进行编译时，对局部变量是通过局部变量在栈上拒帧指针ebp的偏移量
// 来进行访问的，对类对象的成员变量是通过其相对于对象首地址的偏移量来进行
// 访问的，这样不会发生冲突

#include <iostream>

using std::cout;
using std::endl;

#ifdef __cplusplus
extern "C" {
#endif

int gvar = 5;

void testfunc() { gvar++; }

int main()
{
	cout << gvar << endl;
	testfunc();
	cout << gvar << endl;

	system("pause");
	return 0;
}


#ifdef __cplusplus
}
#endif