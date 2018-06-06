#include <iostream>

using std::cout;
using std::endl;

class A
{
public:
	int m_a;
};

class B
{
public:
	int m_b;
};

class C : public A, public B
{

};

int main()
{
	C c;
	cout << &c << endl
		<< reinterpret_cast<B*>(&c) << endl
		<< static_cast<B*>(&c) << endl;

	//前两个的输出值是相同的，最后一个则会在原基础上偏移4个字节，
	//这是因为static_cast计算了父子类指针转换的偏移量，
	//并将之转换到正确的地址（c里面有m_a,m_b，转换为B*指针后指到m_b处），
	//而reinterpret_cast却不会做这一层转换。

	system("pause");
	return 0;
}