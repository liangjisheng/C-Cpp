
// 输出对齐
#include <iostream>
#include <string>
#include <iomanip>

void test_alignment()
{
	using std::cout;
	using std::endl;
	// 这种调整是全局的,一次设置,后面都有效
	cout.setf(std::ios::left);
	int w = cout.width();
	cout << "default field withed = " << w << endl;
	// cout.width(int i)设置是一次性的,只影响紧随其后的一次输出
	cout.width(5);
	cout << "N" << ":";
	cout.widen(8);
	cout << "N * N" << endl;

	for(long i = 1; i <= 100; i *= 10)
	{
		cout.width(5);
		cout << i << ':';
		cout.widen(8);
		cout << i * i << endl;
	}
}

void test_setw()
{
	using std::string;
	using std::cout;
	using std::endl;
	using std::setw;

	int a = 10;
	int b = 20;
	cout.setf(std::ios::right, std::ios::adjustfield);
	cout.fill('*');
	cout << setw(5) << a << endl;
	cout << setw(5) << b << endl;
}


int main()
{
	// test_alignment();
	test_setw();

	system("pause");
	return 0;
}