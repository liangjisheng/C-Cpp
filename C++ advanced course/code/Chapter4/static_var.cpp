
// ���еķ�ֻ���ľ�̬���ݳ�Ա����������֮���ʼ��
// ͬȫ�ֱ�����ȫ�־�̬����һ�����ڶ�����ľ�̬������ʱ���������ʾ������ֵ
// �����ĳ�ʼֵ��Ϊ0

#include <iostream>

using std::cout;
using std::endl;

class Student
{
	double weight;
	static double total_weight;
	static int total_number;
public:
	Student(double w)
	{
		weight = w;
		total_weight += w;
		total_number += 1;
	}
	void Display() const 
	{ cout << "The student's weight is " << weight << endl;}
	static void total_disp();
};


int Student::total_number = 0;

double Student::total_weight = 0.0;

void Student::total_disp()
{
	cout << "total number is " << total_number << endl;
	cout << "total weight is " << total_weight << endl;
}


int main()
{
	Student s1(18.8), s2(16.6), s3(15.5);
	s1.Display();
	s2.Display();
	s3.Display();
	Student::total_disp();

	system("pause");
	return 0;
}