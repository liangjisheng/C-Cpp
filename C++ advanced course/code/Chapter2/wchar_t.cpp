
// C++在库函数中定义了相应的处理Unicode的串处理函数，
#include <iostream>
#include <cstring>

using std::cout;
using std::wcout;
using std::endl;


void test()
{
	char *p = NULL;
	wchar_t s[] = L"ABC";				// 占8个字节
	char name[] = "张三";				// 占5个字节
	wchar_t wname[] = L"张三";			// 占6个字节
	cout << sizeof(wchar_t) << endl;
	cout << sizeof(s) << endl;
	p = (char *)s;
	for(int i = 0; i < sizeof(s); i++)
		cout << (int)p[i] << " ";
	cout << endl;

	cout << s << " ";
	wcout << s << endl;
	// char类型的字符串中，一个汉字字符用两个字节表示，这两个字节的最高位都是1
	// 所以单个字节输出时，除了最后的结束符，都是负数
	for(int i = 0; i < sizeof(name); i++)
		cout << (int)name[i] << " ";
	cout << endl;

	p = (char *)wname;
	// wchar_t类型的字符串，每个字符(包括汉字字符)都是用双字节表示，字符的最高
	// 为就没必要为1了，所以下面输出的是正数
	for(int i = 0; i < sizeof(wname); i++)
		cout << (int)p[i] << " ";
	cout << endl;

	cout << name << endl;
	// 下面的这句话并没有输出张三，但上面的ABC确正确显示，这是控制台程序中的一个
	// 现象，与控制台的缺省语言环境的设置有关，为了能够更好的支持多种语言符号的
	// 显示，IO刘类库依靠一个locale类的对象来设置语言环境，为了能够显示汉字，必须
	// 将控制台语言环境设置成显示中文
	wcout.imbue(std::locale("chs"));
	wcout << wname << endl;

	// 设置成中文之后，还可以输出西文字符
	cout << "test" << endl;
}


int main()
{
	test();

	system("pause");
	return 0;
}