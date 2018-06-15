
#include <iostream>

using std::cout;
using std::endl;

class Mixin1
{
public:
	Mixin1(int i = 0) : mValue(i) {}
	virtual void Mixin1Func() 
	{
		cout << "Mixin1: " << mValue << endl;
	}

private:
	int mValue;
};


class Mixin2
{
public:
	Mixin2(int i = 0) : mValue(i) {}
	virtual void Mixin2Func()
	{
		cout << "Mixin2: " << mValue << endl;
	}

private:
	int mValue;
};


template<typename... Mixins>
class myClass : public Mixins...
{
public:
	myClass(const Mixins&... mixins) : Mixins(mixins)... {}
	virtual ~myClass() {}
};


// test
int main()
{
	myClass<Mixin1, Mixin2> a(Mixin1(11), Mixin2(22));
	a.Mixin1Func();
	a.Mixin2Func();

	myClass<Mixin1> b(Mixin1(33));
	b.Mixin1Func();

	system("pause");
	return 0;
}