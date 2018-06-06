
// 模板函数的代码其实并不能直接编译成二进制代码，
// 其中要有一个“实例化”的过程

template <class T>
class A
{
public:
	void f();					// declare
};