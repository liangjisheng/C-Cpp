
#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

int main()
{
	char iamchar = 'c';
	cout << "iamchar: " << iamchar << endl;
	iamchar = 0x12;
	cout << "iamchar: " << iamchar << endl;

	const char* str = "hello\n";
	cout << str << endl;
	str = "hello \\n world";
	cout << str << endl;

	// Raw字符串定义的格式，它的标准格式为R"附加界定符(字符串)附加界定符"
	// 附加界定符可以没有
	// Raw字符串是C++11引入的，它是为了解决正则表达式里那些烦人的转义字符\
	// 而提供的解决方法。来看看C++之父给出的一个例子，有这样一个正则表达式
	// ('(?:[ˆ\\']|\\.)∗'|"(?:[ˆ\\"]|\\.)∗")|)
	// 在C++中，如果使用转义字符串来表达，则变成
	// ('(?:[ˆ\\\\'] | \\\\.)∗'|\"(?:[ˆ\\\\\"]|\\\\.)∗\")|
	// 使用转义字符后，整个字符串变得很难看懂了
	// 如果使用Raw字符串，改成R"dfp(('(?:[ˆ\\']|\\.)∗'|"(? : [ˆ\\"]|\\.)∗") | )dfp"即可
	// 此处使用的界定字符为"dfp"。
	// 很显然，使用Raw字符串使得代码看起来更清爽，出错的可能性也降低很多
	str = R"**123(hello \n world)**123";
	cout << str << endl;

	system("pause");
	return 0;
}