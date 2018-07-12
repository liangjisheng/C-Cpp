
#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istringstream;		// 支持>>操作,不支持<<操作
using std::ostringstream;		// 支持<<操作,不支持>>操作
using std::stringstream;		// 支持<<操作,支持>>操作
using std::string;
using std::getline;

void test_istringstream()
{
	istringstream istr("1 56.7");
	cout << istr.str() << endl;		// str() return string
	string str = istr.str();
	cout << str << endl;

	unsigned long ulNum = 123;
	double dNum = 12.3;
	cout << "ulNum: " << ulNum << endl;
	cout << "dNum: " << dNum << endl;
	istr >> ulNum;
	istr >> dNum;
	cout << "ulNum: " << ulNum << endl;
	cout << "dNum: " << dNum << endl;
}

// 把一行字符串放入流中，单词以空格隔开。之后把一个个单词从流中依次读取到字符串
void test_istringstream_1()
{
	istringstream istr;
	string line, str;
	cout << "输入几个单词,以空格隔开:" << endl;
	// 从终端接受一行字符,并放入line中
	while(getline(cin, line))
	{
		if(line == "")
			break;
		istr.str(line);		// 将line中的字符放入istr中
		while(istr >> str)
			cout << str << endl;
	}
}

void test_ostringstream()
{
	ostringstream ostr("1234");
	cout << ostr.str() << endl;

	ostr.put('5');
	cout << ostr.str() << endl;

	ostr.put('6');
	cout << ostr.str() << endl;

	ostr << "78";
	cout << ostr.str() << endl;

	// 在接续输入后就会和原来的长度不一样，会有问题
	ostr << '90';
	cout << ostr.str() << endl;

	string str = ostr.str();
	cout << str << endl;
}

void test_stringstream_typeTransform()
{
	// stringstream有两个常用功能:
	// 1:通常用来做数据转换
	// 2:将文件中的所有数据一次性读入内存
	int n = 1234;
	string str = "";
	stringstream stream;

	stream << n;
	stream >> str;
	cout << str << endl;

	// 多次使用stringstream时，要先清空,不能使用stream.str(""),否则还会输出1234
	stream.clear();
	char sz[] = "China";
	stream << sz;
	stream >> str;
	cout << str << endl;

	stream.clear();
	double dNum = 12.34;
	stream << dNum;
	stream >> str;
	cout << str << endl;
}

void test_stringstream_1()
{
	stringstream stream;
	string str;
	while(1)
	{
		// clear()并不清空任何内容，它只是重置了流的状态标志而已
		stream.clear();

		// 去掉下面这行注释，清空stringstream的缓冲，每次循环内存消耗将不再增加!
		// 如果加上注释，则内存消耗将会增加
		stream.str("");

		stream << "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfadsfasdfasdfad";
		stream >> str;

		// 测试每次循环，内存消耗增加了多少
		cout << "size of stream: " << stream.str().length() << endl;
		system("pause");
	}
}

int main()
{
	// test_istringstream();
	// test_istringstream_1();
	// test_ostringstream();
	// test_stringstream_typeTransform();
	test_stringstream_1();

	system("pause");
	return 0;
}