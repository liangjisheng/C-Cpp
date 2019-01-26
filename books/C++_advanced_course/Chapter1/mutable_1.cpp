
#include <iostream>
#include <string>

using namespace std;

// mutable 关键字就是用来解决常函数中不能修改对象的数据成员的问题。
// 如果在某些情况下希望在常函数中任然可以修改某个成员变量的值，那么就在
// 该成员变量的声明前加上关键字mutable，这样不管在什么情况下，这个成员\
// 变量的值都可以修改

class Student
{
	string Name;
	int times_of_getname;
public:
	Student(char* name)
	{
		Name = name;
		times_of_getname = 0;
	}
	string get_name()
	{
		times_of_getname++;
		return Name;
	}
	void PrintTimes() const
	{
		cout << times_of_getname << endl;
	}
};

class Student1
{
	string Name;
	mutable int times_of_getname;
public:
	Student1(char* name)
	{
		Name = name;
		times_of_getname = 0;
	}
	string get_name() const
	{
		times_of_getname++;
		return Name;
	}
	void PrintTimes() const
	{
		cout << times_of_getname << endl;
	}
};


int main()
{
	//const Student s("test");
	// 常量对象调用非const函数，出现编译错误
	//cout << s.get_name() << endl;
	//cout << s.get_name() << endl;
	//s.PrintTimes();

	const Student1 s1("test");
	cout << s1.get_name() << endl;
	cout << s1.get_name() << endl;
	s1.PrintTimes();


	system("pause");
	return 0;
}
