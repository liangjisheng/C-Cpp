
// 输入输出(IO)是指计算机同任何外部设备之间的数据传递。数据可以按"记录"或"数据块"
// 的方式传递，可可以按"流"的方式传递
// 记录只有着内部结构的数据块，记录内部除了有需要处理的实际数据之外，还可能包含
// 附加信息，这些附加信息通常是对本记录数据的描述
// 流是一种抽象概念，他代表了数据的无结构化传递
// 数据的表示分为两种：内部表示和外部表示，标准IO流主要进行字符序列的外部数据
// 与内部数据表示之间的转换，以及在程序与外部设备之间以流的方式传递字符序列
// IO流中，输入输出包括4步：格式化/解析，缓冲，编码转换，传递

// C++中引入模板机制，各个IO流类都是通过模板机制实现的模板类
// typedef basic_ios<char, char_traits<char> > ios;
// typedef basic_istream<char, char_traits<char> > istream;
// typedef basic_ostream<char, char_traits<char> > ostream;
// typedef basic_iostream<char, char_traits<char> > iostream;
// typedef basic_ifstream<char, char_traits<char> > ifstream
// typedef basic_ofstream<char, char_traits<char> > ofstream
// typedef basic_fstream<char, char_traits<char> > fstream

// 所谓类型安全，是指编译器所理解的数据实体(如变量、指针所指向的数据)的类型
// 与数据实体的实际类型或对该数据进行的操作之间保持一致性

// endl被称为I/O操作符,也有翻译成I/O算子.I/O操作符的本质是自由函数,他们并不
// 封装在某个类的内部,使用时也不采用显示的函数调用的形式
// endl		输出时插入换行并刷新流
// ends		输出时在字符后面插入NULL作为尾符
// flush	刷新,把流从缓冲区输出到目标设备
// ws		输入时略去空白字符

// 用户可以编写自己的格式操作符,只要这个操作符函数满足特定的原型即可

#include <iostream>
#include <iomanip>

using namespace std;

// 由于cout的成员函数operator<<()有这样一种重载形式
// ostream& ostream::operator<<(ostream& (*_Pfn)(ostream&));
// 只要满足下面的函数原型,就可以作为一个操作符
ostream& Tab(ostream &outs)
{
	for(int i = 0; i < 4; i++)
		outs << '-';
	return outs;
}

ostream& Money(ostream &outs)
{
	outs.setf(ios::left, ios::adjustfield);
	outs << '$' << setw(12) << setfill('#');
	return outs;
}

int main()
{
	double amount = 4532.64;
	cout << "The amount is " << Tab << Money << amount << endl;

	system("pause");
	return 0;
}