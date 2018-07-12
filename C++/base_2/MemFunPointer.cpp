
#include <iostream>

using std::cout;
using std::endl;

class Person
{
public:
	int value;
	void Speak()
	{
		cout << "I am a person" << endl;
		printf("0x%p\n", &Person::Speak);
	}
	virtual void hello() { cout << "Person say \"Hello\"" << endl; }

	Person() { value = 1; }
};

class Person1 : public Person
{
public:
	void Speak() { cout << "I am Person1" << endl; }
	virtual void hello() { cout << "Person1 say \"Hello\"" << endl; }
	Person1() { value = 2; }
};

// 定义指向Person类无参数无返回值的成员函数指针
typedef void (Person::*Tp)();
// 定义指向Person1类无参数无返回值的成员函数指针
typedef void (Person1::*Tq)();


int main()
{
	Person pe;
	int i = 1;
	Tp ip;
	ip = &Person::Speak;
	(pe.*ip)();
	// 下面是几种错误的写法
	// pe.*ip();
	// pe.(*ip)();
	// (pe.(*ip))();

	cout << endl;
	Person1 pe1;
	Tq iq = (void (Person1::*)())ip;	// 强制转换
	(pe1.*iq)();

	cout << endl;
	iq = &Person1::Speak;			// iq指向了Person1类的Speak函数
	ip = (void (Person::*)())iq;	// ip接收强制转化后的iq指针
	(pe1.*ip)();
	(pe1.*iq)();

	cout << endl;
	ip = &Person::hello;
	(pe.*ip)();
	(pe1.*ip)();

	iq = (void (Person1::*)())ip;
	(pe1.*iq)();

	system("pause");
	return 0;
}