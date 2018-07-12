
#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
	static int getValue()
	{
		static int i = 0;
		i += 1;
		cout << i << endl;
		return i;
	}
};

class Derived : public Base
{
public:
	void getV(const Derived &derived_obj);
};

void Derived::getV(const Derived &derived_obj)
{
	derived_obj.getValue();
	getValue();
}

int main()
{
	Base::getValue();
	Derived::getValue();
	Derived d1;
	Derived d2;
	d2.getV(d1);

	system("pause");
	return 0;
}