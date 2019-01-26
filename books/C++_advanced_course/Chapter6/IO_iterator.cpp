
// 可以将标准输入对象cin组装成输入流迭代子(istream iterator),也可以将标准输出
// 对象cout组装成输出流迭代子(ostream iterator),以此来完成输入输出操作


#include <iostream>
#include <iterator>		// ostream_iterator and istream_iterator

using std::cin;
using std::cout;
using std::endl;


int main()
{
	cout << "Enter two integers:";
	// create istream_iterator for reading int values from cin
	// 只能输入整数，输入其它类型的值会抛出运行时异常
	std::istream_iterator<int> inputInt(cin);
	int number1 = *inputInt;		// read int from standard input
	// 通过++将迭代子移动到下一个输入数据处
	++inputInt;						// move iterator to the next input value
	int number2 = *inputInt;		// read int from standard input

	// create ostream_iterator for writing int value to cout
	// 只能输出int类型的数据，输出其它类型的数据，会出现编译错误
	std::ostream_iterator<int> outputInt(cout);
	cout << "The sum is:";
	// 输出过程以赋值方式进行
	*outputInt = number1 + number2;	// output result to cout
	cout << endl;

	system("pause");
	return 0;
}

