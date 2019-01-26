
// 目前广泛使用的编码模式有3种，对应于3中字符类型
// 第一种是单字节字符集(single-byte character set or SBCS).在这种模式下所有
// 字符都只用一个字节表示，ASCII是SBCS。
// 第二种是多字节字符节(multi-byte character set or MBCS).一个MBCS编码包含
// 一些一个字节长的字符，而另外一些字符大于一个字节的长度。用在windows里的
// MBCS包含两种字符类型，单字节字符和双字节字符，由于windows里使用的多字节
// 字符绝大部分都是两个字节长，所以MBCS常被DBCS代替
// 第三种是Unicode编码。Unicode是一种所有的字符都使用两个字节编码的编码模式。


#include <iostream>
#include <string>

using namespace std;

int main()
{
	char chs[] = "Hello";
	string s0("");
	string s1(chs);
	string s2("World");
	string s3(chs, 1, 3);
	string s4(s2);
	string s5(chs, 3);
	string s6(10, 'k');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;

	cout << "sizeof s1 is " << s1.size() << endl;
	cout << "length of s1 is " << s1.length() << endl;
	cout << "capacity of s1 is " << s1.capacity() << endl;
	cout << "max_size of s1 is " << s1.max_size() << endl;
	cout << "length of s0 is " << s0.length() << endl;
	cout << "capacity of s0 is " << s0.capacity() << endl;

	if(s0.empty())
		cout << "s0 is empty" << endl;

	system("pause");
	return 0;
}

