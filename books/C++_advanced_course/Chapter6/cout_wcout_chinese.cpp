
#include <iostream>
#include <locale>
#include <fstream>

using std::cout;
using std::endl;
using std::wcout;
using std::locale;
using std::ofstream;
using std::wofstream;

// 测试字符串
void test_1()
{
	// 默认Clocale情况下，cout可以直接输出中文，但wcout确不行，
	// 需要将其locale设为本地语言
	cout << "test" << endl;
	cout << "测试" << endl;
	cout << L"test" << endl;
	cout << L"测试" << endl;
	cout << endl;

	wcout << "test" << endl;
	wcout << "测试" << endl;
	wcout << L"test" << endl;
	// 将locale设为本地, 也可以使用wcout.imbue(locale(""));
	// 但这样会改变wcout的所有locale设置，比如数字1234会变成1,234
	// 而下面的这句话只改变的字符串的输出
	wcout.imbue(locale(locale(), "", LC_CTYPE));
	wcout << L"测试" << endl;		// 没有将locale设为本地的话就不会输出
	cout << endl;

	wcout << "test" << endl;
	// 将locale设为本地后，如果这样写中文不会输出
	wcout << "测试" << endl;
	wcout << L"test" << endl;
	wcout << L"测试" << endl;
}

// 测试中文文件名及中文内容
void test_2()
{
	ofstream ofs("test_1_1.txt");
	ofs << "this is a test line" << endl;
	ofs.close();

	ofs.open("测试_0_1.txt");
	ofs << "this is a test line" << endl;
	ofs.close();

	ofs.open("test_1_0.txt");
	ofs << "这是一个测试行" << endl;
	ofs.close();

	ofs.open("测试_0_0.txt");
	ofs << "这是一个测试行" << endl;
	ofs.close();

	//ofstream ofs(L"test_1_1.txt");			// error
	//ofs << L"this is a test line" << endl;	// error
	//ofs.close();

	//ofs.open(L"测试_0_1.txt");
	//ofs << L"this is a test line" << endl;
	//ofs.close();

	//ofs.open(L"test_1_0.txt");
	//ofs << L"这是一个测试行" << endl;
	//ofs.close();

	//ofs.open(L"测试_0_0.txt");
	//ofs << L"这是一个测试行" << endl;
	//ofs.close();

	// 如果要输出中文的话，需要将全局locale设为本地语言,默认情况下
	// wofstream是不能输出中文的
	locale &loc = locale::global(locale(locale(), "", LC_CTYPE));
	wofstream wofs(L"w_test_1_1.txt");
	wofs << L"this is a test line" << endl;
	wofs.close();

	wofs.open(L"w_测试_0_1.txt");
	wofs << L"this is a test line" << endl;
	wofs.close();

	wofs.open(L"w_test_1_0.txt");
	wofs << L"这是一个测试行" << endl;
	wofs.close();

	wofs.open(L"w_测试_0_0.txt");
	wofs << L"这是一个测试行" << endl;
	wofs.close();

	// 恢复原来的设置,wcout不能输出中文，在这句之后
	locale::global(loc);

	wcout << L"test" << endl;
	wcout << L"测试" << endl;
}

int main()
{
	// test_1();
	test_2();

	system("pause");
	return 0;
}