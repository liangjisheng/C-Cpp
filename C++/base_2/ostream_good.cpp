
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <locale>

using std::cout;
// 告诉流输出一个回车符并刷新其输出缓冲区
using std::endl;
using std::cerr;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;
using std::wcout;
using std::locale;

void test_cout()
{
	// 调用good方法确定流是否是好的
	if(cout.good())
		cout << "cout good!" << endl;
	if(cout.fail())
		cerr << "unable to flush to standard out" << endl;
	cout.clear();
}

void test_cin()
{
	// 对于大部分目的而言，理解输入流的正确方法是把它看作是单向
	// 的清洗槽。数据落入其中并进入变量。方法unget会打破这种模型
	// 它允许把数据推回到清洗槽中。以此unget会引起流后退一个位置
	// 其本质是把最后一个字符读回到流中
	char ch1, ch2, ch3, ch4;
	cout << "input three characters : " << endl;
	cin >> ch1 >> ch2 >> ch3;
	cin.unget();
	cin >> ch4;
	cout << "ch3 = " << ch3 << endl;
	cout << "ch4 = " << ch4 << endl;

	// putback()：就向unget一样，允许在流中后退一个字符
	// 二者的区别在于，putback取流中要后退的字符作为参数。
	char ch5, ch6;
	cout << "input a character : ";
	cin >> ch5;
	cin.putback(ch1);	// ch1是输入流中的下一个字符
	cin >> ch6;
	cout << "ch5 = " << ch5 << endl;
	cout << "ch1 = " << ch1 << endl;
	cout << "ch6 = " << ch6 << endl;

	// peek()允许预览下一个值
	int next = cin.peek();
	if(isdigit(next))
		cout << (char)next << " is digit" << endl;
	else
		cout << (char)next << " is not digit" << endl;
}

void test_cin_1()
{
	char buffer[128] = {0};
	cout << "input some characters: " << endl;
	cin.getline(buffer, 127);		// 会删除流中的换行字符
	cout << buffer << endl;
	char ch;
	int next = cin.get();
	ch = (char)next;
	cout << ch << " " << next << endl;
}

void test_cin_2()
{
	int sum = 0;
	if(!cin.good())
	{
		cerr << "Standard input is in a bad state!" << endl;
		exit(1);
	}

	int number = 0;
	char ch = '\0';
	cout << "input some numbers :" << endl;
	while(true)
	{
		if(cin.eof())		// 如果不想继续输入了，就按Ctrl+Z,表示到达的流的末尾
			break;
		else if(cin.good())
		{
			cin >> number;
			// cin >> ch;
			//if(' ' == ch)
				//break;
			sum += number;
		}
		else
		{
			cin.clear();
			string badToken;
			cin >> badToken;
			cerr << "WARNING:Bad input encounter:" << badToken << endl;
		}
	}
	cout << "The sum is " << sum << endl;
}

void test_cin_3()
{
	char ch;
	while(!cin.eof())
	{
		cin >> ch;
		cout << "char: " << ch << endl;
	}
}

void test_cin_4()
{
	char x;
	while(cin >> x)
		cout << "char: " << x << endl;
}

// 可以在任何输入流与输出流之间建立链接。从而提供一种“一旦访问就刷新输出”的行为
// 换句话说，从输入流请求数据时，与其链接的输出流会自动刷新输出。这个行为可以用于
// 所有的流，但是对于可能相互依赖的文件流尤其有用
// 流链接用方法tie()来实现。要把输出流绑定到一个输入流上，可以在输入流上调用tie()
// 并把输出流的地址传递给它。要断开这个链接，传递NULL即可。
// 下面这段程序把一个文件的输出流绑到了另一个文件的输入流上。也可以把它绑定到同一个
// 文件的输入流上，不过要同时读写一个文件，双向I/O可能更好。
void link_stream()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	in.tie(&out);	// 将输出流out绑定到输入流in
	out << "hello,world";
	out.flush();
	string text = "";
	in >> text;
	in.close();
	out.close();

	cout << text << endl;
}

// outFile.tie(&anotherOutFile);
// 这种关系表示，每次向一个文件写数据时，就会向另一个文件写入已经发送
// 的缓冲数据。可以使用这种机制保持二个相关文件之间的同步

void test_locale()
{
	// 美国英语本地化环境附加到宽字符控制台输出流
	// wcout.imbue(locale("en_US"));	// Runtime error
	wcout.imbue(locale("C"));			// 输出数字时不带任何标点
	wcout << 32767 << endl;

	locale loc("");		// 创建了一个本地化环境
	if(loc.name().find("en_US") == string::npos
		&& loc.name().find("United States") == string::npos)
		cout << "not the en_US locale" << endl;
	else
		cout << "the en_US locale" << endl;
}


int main()
{
	// test_cout();
	// test_cin();
	// test_cin_1();
	// test_cin_2();
	// test_cin_3();
	// test_cin_4();
	// link_stream();
	test_locale();

	system("pause");
	return 0;
}