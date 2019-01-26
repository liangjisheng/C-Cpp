
// 1、利用宏可以防止头文件在一个源文件中被包含多次
// 2、断言assert是仅在Debug版本起作用的宏，用于检查不该发生的情况。为了不再程序的
// Debug和Release版本引起差别，assert不应该产生任何副作用。所以assert不是函数
// 而是宏，可以把assert看成一个在任何系统状态下都可以使用的安全的无害测试手段
// 3、利用宏可以实现一些特殊操作，利用内链汇编获取类的非静态成员函数的地址

#define mymax(a, b) ((a) > (b)) ? (a) : (b)

// 如果宏的实现比较复杂，不适合在一行中写完，则可以分成多行书写，在需要续行
// 的那一行的末尾加一个'\',表示下一行任然是宏定义的一部分
// 最后一行不用'\',且每个'\'后面不要跟任何字符，空格也不要，否则会编译错误
#define Compare(a, b) if((a) > (b))\
	printf("The first one is bigger.\n");\
	else\
	printf("The fist one is not bigger.\n");

// 尽管宏可以多行定义，但是在宏展开的时候，被展开的宏的源程序中任然是被书写在
// 一行当中，在某些情况下会引发编译错误

// #将宏参数置于字符串中，##将宏参数与别的字符组合成新的标识符

#include <iostream>

using std::cout;
using std::endl;

#define PrintVar(v, index) cout << #v#index" is " << v##index << endl;

int main()
{
	int i1 = 1, i2 = 2, i3 = 3;
	PrintVar(i, 1);
	PrintVar(i, 2);
	PrintVar(i, 3);

	system("pause");
	return 0;
}