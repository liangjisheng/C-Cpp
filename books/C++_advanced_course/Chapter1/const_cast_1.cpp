
#include <iostream>  

using std::cout;
using std::endl;
using std::cin;

// const_cast操作符，只能将const type*类型转换成type*类型，或者将
// const_type&转换成type&类型，远类型与目标类型除了const属性之外，
// 其他方面必须相同

// 一个变量被定义为只读变量(常变量),那么他就永远是常变量，const_cast取消的
// 是对间接引用时的改写限制(即只针对指针或引用)，而不能改变变量本身的const属性

void ConstTest1()
{
	const int a = 5;
	int *p = NULL;
	p = const_cast<int*>(&a);
	(*p)++;
	// 输出为5，并不表明常量a的值没有改变，而是编译器在优化代码时，将a
	// 替换成了文字常量5.实际上a的值已经变成了6.
	cout << a << endl << endl;
}

void ConstTest2()
{
	int i = 0;
	cout << "please input a integer:";
	cin >> i;
	const int a = i;
	// ()不能省略，哪怕只是一个变量
	int &r = const_cast<int&>(a);
	r++;
	// 由于a无法转化成对应的文字常量，所以它显示出被修改之后的值
	cout << a << endl;
}

int main()
{
	ConstTest1();
	ConstTest2();

	system("pause");
	return 0;
}