
// ��C++�У��ṹ��һ���������������ͣ����ýṹ�嶨�����ʱ������Ҫ����C����
// ����������struct�ؼ��֣�������ʹ��typedef struct structname structname��
// ��ʽ�����������ڽṹ����Ĭ�ϵķ���Ȩ����public,
// �����struct��û����ʾ�����κι��캯������ô�ṹ������������C������������
// ��������˳��ָ�����ݳ�Ա��ֵ�İ취���г�ʼ����

#include <iostream>

using std::cout;
using std::endl;


class A
{
public:
	int n1;
	int n2;
	void show();
};


void A::show() { cout << n1 << "," << n2 << endl; }


struct Room
{
	int floor;
	int No;
};

struct Student
{
	int age;
	int score;
	Student(int a, int s)
	{
		age = a;
		score = s;
	}
};


int main()
{
	Room r[3] = {{1, 101}, {2, 201}, {3, 301} };
	Student s(18, 80);
	cout << "The rooms are:";
	cout << r[0].floor << "-" << r[0].No << ",";
	cout << r[1].floor << "-" << r[1].No << ",";
	cout << r[2].floor << "-" << r[2].No << endl;
	cout << "The student is " << s.age;
	cout << " years old and he's score is " << s.score << endl;

	// Student������ʾ���幹�캯�������Բ������������������ֵ
	// Student s1 = {18, 80};						// error
	A a1 = {10, 11};								// ok
	a1.show();

	system("pause");
	return 0;
}

