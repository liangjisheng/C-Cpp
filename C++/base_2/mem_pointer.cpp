
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Student
{
public:
	Student(int i, string _name) : schoolNumber(i), name(_name) {}
	void getInfo() const 
	{ cout << "name: " << name << ",number: " << schoolNumber << endl; }
	void setInfo(string _name, int id)
	{
		name = _name;
		schoolNumber = id;
	}
// private:
	int schoolNumber;
	string name;
};


int main()
{
	Student s1(1, "test");
	Student *p = &s1;
	// 数据成员指针与函数成员指针
	string Student:: *ps_Student = &Student::name;
	// 指针指向某个类中int类型的成员
	int Student:: *pi_Student = &Student::schoolNumber;
	void (Student::*pf_Screen)() const = &Student::getInfo;
	void (Student::*pf_Set_Screen)(string, int) = &Student::setInfo;

	cout << s1.*ps_Student << endl;
	cout << s1.*pi_Student << endl;
	s1.getInfo();
	(s1.*pf_Screen)();
	(p->*pf_Screen)();

	system("pause");
	return 0;
}