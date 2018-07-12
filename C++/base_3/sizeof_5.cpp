#include"iostream"
#include"complex"
using namespace std;

class Base{
public:
	Base() { cout<<"Base-ctor"<<endl; }
	~Base() { cout<<"Base-dtor"<<endl; }
	virtual void f(int) { cout<<"Base::f(int)"<<endl; }
	virtual void f(double) { cout<<"Base::f(double)"<<endl; }
	virtual void g(int i=10) { cout<<"Base::g()"<<i<<endl; }
	void g2(int i=10) { cout<<"Base::g2()"<<i<<endl; }
};

class Derived : public Base
{
public:
	Derived() { cout<<"Derived-ctor"<<endl; }
	~Derived() { cout<<"Derived-dtor"<<endl; }
	void f(complex<double>) { cout<<"Derived::f(complex)"<<endl; }
	virtual void g(int i=20) { cout<<"Derived::g()"<<i<<endl; }
};

int main()
{
	Base b;
	Derived d;
	Base* pb=new Derived;
	// Base有虚函数，Base中只有一个虚函数表指针
	// Derived和Base一样
	cout<<sizeof(Base)<<" tt"<<endl;		// 4
	cout<<sizeof(Derived)<<" bb"<<endl;	// 4

	system("pause");
	return 0;
}