
// 由一种类对象转换成另一种类对象，这种转换无法自动进行，必须定义相关的转换
// 函数，就是类的单参数构造函数，或者将类类型作为类型转换操作符函数进行重载

// 数据类型转换相当于一次函数调用，调用的结果是生成一个新的数据实体，或者生成
// 一个指向原数据实体但解释方式发生变化的指针(或者引用).程序员必须对转换的
// 安全性负责，可以通过两种途径实现：一是利用C++提供的数据类型动态检查机制
// 在一个就是利用程序的内在逻辑保证类型转换的安全性

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;


class Student
{
	char name[20];
	int age;
public:
	Student() { memset(name, 0, 20); age = 0; }
	Student(char *s, int a)
	{
		cout << "student(char, int)" << endl;
		strcpy(name, s);
		age = a;
	}
	Student(const Student& src)
	{
		cout << "Student copy constructor" << endl;
		strcpy(name, src.name);
		age = src.age;
	}
	friend class Team;
};


class Team
{
	int members;
	Student monitor;
public:
	Team() { members = 0; }
	Team(const Student& s) : monitor(s), members(0) 
	{ cout << "Student to Team" << endl; }
	void Display() const;
};


void Team::Display() const
{
	cout << "The number of the members is: ";
	if(0 == members)
		cout << "unknown" << endl;
	else
		cout << members << endl;

	cout << "The name of the monitor is: " << monitor.name << endl;
	cout << "The age of the monitor is: " << monitor.age << endl;
}


ostream& operator<<(ostream& out, const Team& t)
{
	t.Display();
	return out;
}


// A类可以转换为int,double,float这三种类型,转换函数只能定义为类的成员函数
// 转换函数通常权限为public，否则无法被显示的调用，转换函数没有参数，也不
// 显式给出返回类型
class A
{
public:
	operator int() { return 1; }
	operator double() { return 1.5; }
	operator float();
};

A::operator float() { return 1.1; }


int main()
{
	Student s("test", 18);
	// <<并不接受Student类对象作为参数，将转换为Team类对象
	cout << s << endl;

	A obj;
	cout << "Treating obj as an integer,its values is:" << (int)obj << endl;
	cout << "Treating obj as an float,its values is:" << (float)obj << endl;
	cout << "Treating obj as an double,its values is:" << (double)obj << endl;

	system("pause");
	return 0;
}