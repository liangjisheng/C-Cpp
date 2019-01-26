
// 多重继承的情况下，派生类与基类的关系变的更为复杂，其中一个容易出现的问题
// 某个基类沿着不同的路径被派生类继承(即形成所谓的菱形继承)从而在一个派生类
// 对象中存在同一个基类对象的多个拷贝
// 虚拟继承就是解决在类EGStudent中有两个Person对象的问题，在构造EGStudent
// 类对象的时候，EGStudent类的祖先类Person的对象只会被构造一次

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Person
{
protected:
	string IdPerson;
	string Name;
public:
	Person() {}
	Person(string s1, string s2)
	{
		IdPerson = s1;
		Name = s2;
	}
};

// 为了实现虚拟继承，派生类对象的大小会增加4字节
class Student : public virtual Person
{
	int No;
public:
	Student(string s1, string s2, int n) : Person(s1, s2), No(n) {}
};

class Employee : public virtual Person
{
	int No;
public:
	Employee(string s1, string s2, int n) : Person(s1, s2), No(n) {}
};

class EGStudent : public virtual Employee, public virtual Student
{
	int No;
public:
	// 由于在EGStudent类对象中，只存在一份Person类对象的拷贝，所以Student
	// Employee的构造函数实际上并未对Person类对象进行初始化，也就是说在
	// EGStudent类的构造函数中，Person类对象单独构造，下面没有显示调用
	// Person类的构造函数，所以IdPerson,Name是空的
	EGStudent(string s1, string s2, int n) 
		: Employee(s1, s2, n), Student(s1, s2, n), No(n) {}
	void show()
	{ cout << IdPerson << "," << Name << "," << No << endl; }
};


int main()
{
	EGStudent one("23243232324232543", "name", 123);
	one.show();
	cout << "sizeof(string) = " << sizeof(string) << endl;
	cout << "sizeof(Person) = " << sizeof(Person) << endl;
	cout << "sizeof(Employee) = " << sizeof(Employee) << endl;
	cout << "sizeof(Student) = " << sizeof(Student) << endl;
	cout << "sizeof(EGStudent) = " << sizeof(EGStudent) << endl;

	system("pause");
	return 0;
}