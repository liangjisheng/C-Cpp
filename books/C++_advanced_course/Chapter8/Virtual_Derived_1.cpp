
// ���ؼ̳е�����£������������Ĺ�ϵ��ĸ�Ϊ���ӣ�����һ�����׳��ֵ�����
// ĳ���������Ų�ͬ��·����������̳�(���γ���ν�����μ̳�)�Ӷ���һ��������
// �����д���ͬһ���������Ķ������
// ����̳о��ǽ������EGStudent��������Person��������⣬�ڹ���EGStudent
// ������ʱ��EGStudent���������Person�Ķ���ֻ�ᱻ����һ��

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

// Ϊ��ʵ������̳У����������Ĵ�С������4�ֽ�
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
	// ������EGStudent������У�ֻ����һ��Person�����Ŀ���������Student
	// Employee�Ĺ��캯��ʵ���ϲ�δ��Person�������г�ʼ����Ҳ����˵��
	// EGStudent��Ĺ��캯���У�Person����󵥶����죬����û����ʾ����
	// Person��Ĺ��캯��������IdPerson,Name�ǿյ�
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