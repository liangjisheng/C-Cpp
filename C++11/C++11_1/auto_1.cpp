
#include<iostream>

using std::cout;
using std::endl;

class A
{
public:
	auto testwork(int a);
};

auto A::testwork(int a) { cout << __FUNCTION__ << endl; }

int main()
{
	A a;
	a.testwork(1);

	system("pause");
	return 0;
}