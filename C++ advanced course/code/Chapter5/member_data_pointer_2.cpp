
// ��Ա����ָ�����ڵײ�ʵ�ֵģ���ŵ��Ƕ�������ݳ�Ա����ڶ����׵�ַ��ƫ����
// �������������˵����Ա����ָ�벢����һ��������ָ�룬ͨ����ָ��������ʱ��
// ʵ�����ǽ���ָ���ʾ��ƫ�����ӵ������׵�ַ��

#include <iostream>

using std::cout;
using std::endl;

class Student
{
public:
	int age;
	double score;
	Student(int a, double s) { age = a; score = s; }
};

void PrintContent(void *addr, int n)
{
	char *p = (char*)addr;
	for(int i = 0; i < n; i++)
		cout << (int)p[i] << " ";
	cout << endl;
}


int main()
{
	Student me(20, 75.5);
	int Student::* pi;
	double Student::* pd;

	cout << sizeof(pi) << endl;
	cout << sizeof(pd) << endl;
	pi = &Student::age;
	pd = &Student::score;
	PrintContent(&pi, 4);			// �鿴��Ա����ָ�������
	PrintContent(&pd, 4);

	system("pause");
	return 0;
}