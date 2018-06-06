
// 一个类的对象生成后，他的某个成员变量的地址实际上由两个因素决定：对象的首地址
// 和该成员变量在对象之内的偏移量。成员数据指针就是用来保存类的某个成员数据在类
// 对象内的偏移量的

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
	// 计算年龄的平均值
	double age_avg = average(my, &Student::age, 5);
	// 计算分数的平均值
	double score_avg = average(my, &Student::score, 5);
	cout << age_avg << endl;
	cout << score_avg << endl;

	system("pause");
	return 0;
}