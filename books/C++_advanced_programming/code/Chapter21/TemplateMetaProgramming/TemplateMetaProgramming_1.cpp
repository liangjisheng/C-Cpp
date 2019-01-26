
#include <iostream>

using std::cout;
using std::endl;

// 模板元编程可以在编译是展开循环，而不是在运行时执行循环。

template<int i>
class Loop
{
public:
	template<typename FuncType>
	static inline void Do(FuncType func)
	{
		func(i);
		Loop<i - 1>::Do(func);
		func(i);
	}
};


// 特化，结束递归的基础模板,结束时的模板什么也不做
template<>
class Loop<0>
{
public:
	template<typename FuncType>
	static inline void Do(FuncType /* func */) {}
};


void DoWork(int i)
{
	cout << "DoWork(" << i << ")" << endl;
}


// test
int main()
{
	Loop<3>::Do(DoWork);

	system("pause");
	return 0;
}