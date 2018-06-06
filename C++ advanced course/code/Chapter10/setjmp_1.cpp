
// C语言处理异常通常有3种典型的方法
// 1:出错信息可通过函数的返回值获得，如果函数返回值不能用，则可设置
// 一全局错误判断标志(标准C语言中errno()和perrno()函数支持这一方法)
// 2:可使用C标准库中一般不太常用的信号处理系统，利用signal()函数(判断
// 事件发生类型)和raise()函数(产生事件),由于信号产生库的使用这必须理解
// 和安装合适的信号处理系统，所以使用这两个函数进行出错处理时应紧密结合
// 各信号产生库，对于大型项目而言，不同库之间的信号可能会产生冲突
// 3:使用C标准库中的非局部跳转函数:setjmp()和longjmp().setjmp()函数可在
// 程序中存储一典型的正常状态,如果程序发生错误，longjmp()可恢复setjmp()
// 函数的设定状态，从而实现goto语句无法实现的"长跳转".事先被存储的地点
// 在恢复时，可以得知是从哪里跳转过来的，也就是说可以确定错误发生的地点

#include <iostream>
#include <setjmp.h>

using namespace std;

class gname
{
public:
	gname() { cout << "gname" << endl; }
	~gname() { cout << "~gname" << endl; }
};

jmp_buf g_jmp;

void test()
{
	gname name;
	for(int i = 0; i < 3; i++)
		cout << "There is no interesting gname." << endl;
	longjmp(g_jmp, __LINE__);
}

int main()
{
	// setjmp(jmp_buf);把当前进程状态的所有相关信息存放在jmp_buf类型的变量
	// 中，并返回0，这样他的行为像通常的函数.然而如果使用同一个jmp_buf调用
	// longjmp(),控制流就会回到setjmp()执行的地方，并且将longjmp()的第二个
	// 参数作为调用setjmp()的返回值.如果程序中有多个jmp_buf就可以弹出程序的
	// 多个不同位置的信息
	if(setjmp(g_jmp) == 0)
	{
		cout << "one,two,three..." << endl;
		test();
	}
	else
		cout << "It's fantastic!" << endl;

	system("pause");
	return 0;
}