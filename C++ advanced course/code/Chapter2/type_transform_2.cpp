
// reinterpret_cast实现函数指针转换

#include <iostream>

using std::cout;
using std::endl;

typedef void (*pfunc)();

void func1() { cout << "this is func1(),return void" << endl; }

int func2()
{
	cout << "this is func2(),return int" << endl;
	return 1;
}


int main()
{
	pfunc FuncArray[2];
	FuncArray[0] = func1;
	// 函数指针类型int (*)()转换为void (*)(),只能通过reinterpret_cast进行
	FuncArray[1] = reinterpret_cast<pfunc>(func2);
	for(int i = 0; i < 2; i++)
		(*FuncArray[i])();

	system("pause");
	return 0;
}

