
// һ����Ķ������ɺ�����ĳ����Ա�����ĵ�ַʵ�������������ؾ�����������׵�ַ
// �͸ó�Ա�����ڶ���֮�ڵ�ƫ��������Ա����ָ����������������ĳ����Ա��������
// �����ڵ�ƫ������

#include <iostream>

using std::cout;
using std::endl;

class Student
{
public:
	int age;
	int score;
};

double average(Student* objs, int Student::* pm, int count)
{
	int result = 0;
	for(int i = 0; i < count; i++)
		result += objs[i].*pm;
	return (double)(result) / count;
}


int main()
{
	Student my[5] = { {17, 75}, {19, 85}, {20, 80}, {21, 78}, {22, 83} };
	// ���������ƽ��ֵ
	double age_avg = average(my, &Student::age, 5);
	// ���������ƽ��ֵ
	double score_avg = average(my, &Student::score, 5);
	cout << age_avg << endl;
	cout << score_avg << endl;

	system("pause");
	return 0;
}