
#include <iostream>

using namespace std;

void test()
{
	char str[10] = "ABC我们";
	wchar_t wstr[20] = L"ABC我们";
	cout << "cout << str: " << str << endl;			// ok
	// 由于在cout中并没有进行相应的操作符重载，所以wchar_t类型的
	// 参数只是被当做一个指针进行输出
	cout << "cout << wstr: " << wstr << endl;		// address
	wcout << "wcout << str: " << str << endl;		// ok
	// English Ok,Chinese error,than the wcout stream is wrong
	// 默认情况下,全局locale是"C"locale,wcout并不能输出宽字符的汉字字符
	// wcout << str;失败,导致后面的所有利用wcout对象进行输出全部处于阻塞
	// 状态
	wcout << "wcout << wstr: " << wstr << endl;		
	cout << "******" << endl;						// ok
	wcout << "wcout << str: " << str << endl;		// non output
}

void test1()
{
	char str[10] = "ABC我们";
	wchar_t wstr[20] = L"ABC我们";
	cout << "cout << str: " << str << endl;			// ok
	cout << "cout << wstr: " << wstr << endl;		// address
	wcout << "wcout << str: " << str << endl;		// ok
	cout << "******" << endl;						// ok

	wcout.imbue(locale("CHS"));
	wcout << "wcout << wstr: " << wstr << endl;		
	// 此时char*被解释成单字节编码的字符串
	wcout << "wcout << str: " << str << endl;		// ABC,no Chinese
}

int main()
{
	// test();
	test1();

	system("pause");
	return 0;
}