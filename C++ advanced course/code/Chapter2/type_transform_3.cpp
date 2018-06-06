
// ��һ�������ת������һ�����������ת���޷��Զ����У����붨����ص�ת��
// ������������ĵ��������캯�������߽���������Ϊ����ת��������������������

// ��������ת���൱��һ�κ������ã����õĽ��������һ���µ�����ʵ�壬��������
// һ��ָ��ԭ����ʵ�嵫���ͷ�ʽ�����仯��ָ��(��������).����Ա�����ת����
// ��ȫ�Ը��𣬿���ͨ������;��ʵ�֣�һ������C++�ṩ���������Ͷ�̬������
// ��һ���������ó���������߼���֤����ת���İ�ȫ��

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


// A�����ת��Ϊint,double,float����������,ת������ֻ�ܶ���Ϊ��ĳ�Ա����
// ת������ͨ��Ȩ��Ϊpublic�������޷�����ʾ�ĵ��ã�ת������û�в�����Ҳ��
// ��ʽ������������
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
	// <<��������Student�������Ϊ��������ת��ΪTeam�����
	cout << s << endl;

	A obj;
	cout << "Treating obj as an integer,its values is:" << (int)obj << endl;
	cout << "Treating obj as an float,its values is:" << (float)obj << endl;
	cout << "Treating obj as an double,its values is:" << (double)obj << endl;

	system("pause");
	return 0;
}