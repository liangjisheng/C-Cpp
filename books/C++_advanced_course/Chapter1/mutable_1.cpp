
#include <iostream>
#include <string>

using namespace std;

// mutable �ؼ��־�����������������в����޸Ķ�������ݳ�Ա�����⡣
// �����ĳЩ�����ϣ���ڳ���������Ȼ�����޸�ĳ����Ա������ֵ����ô����
// �ó�Ա����������ǰ���Ϲؼ���mutable������������ʲô����£������Ա\
// ������ֵ�������޸�

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
	// ����������÷�const���������ֱ������
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
