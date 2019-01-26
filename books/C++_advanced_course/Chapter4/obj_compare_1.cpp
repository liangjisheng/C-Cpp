
// 除了可以用成员函数的方式实现关系运算符的重载，还可以用友元函数的方式实现

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class Student
{
	double average_score;
	int age;
public:
	Student(double s, int a) 
	{
		average_score = s;
		age = a;
	}
	Student(double s) { average_score = s; age = 20; }

	bool operator<(const Student &obj)
	{ return average_score < obj.average_score; }
	bool operator>(const Student &obj)
	{ return average_score > obj.average_score; }
	bool operator==(const Student &obj)
	{ return (!operator<(obj) && !operator>(obj)); }
	bool operator >= (const Student &obj)
	{ return !operator<(obj); }
	bool operator <= (const Student &obj)
	{ return !operator>(obj); }
	bool operator != (const Student &obj)
	{ return !operator==(obj); }

	friend ostream& operator<<(ostream &os, const Student &obj);

	// 将Student类转换为double类型
	operator double() { return average_score; }
};


ostream& operator<<(ostream &os, const Student &obj)
{
	os << "score is " << obj.average_score << ", age is " << obj.age << endl;
	return os;
}


int main()
{
	Student s1(80.5, 18);
	Student s2(83.3, 19);
	cout << "Student1 " << s1;
	cout << "Student2 " << s2;
	double d1 = s1;
	double d2 = s2;
	cout << d1 << endl;
	cout << d2 << endl;

	Student s3 = d1;
	Student s4 = d2;
	cout << s3;
	cout << s4;

	char *fig = NULL;
	fig = (s1 > s2) ? "" : "not";
	cout << "Student one is " << fig << " > " << "student two" << endl;
	fig = (s1 < s2) ? "" : "not";
	cout << "Student one is " << fig << " < " << "student two" << endl;
	fig = (s1 == s2) ? "" : "not";
	cout << "Student one is " << fig << " == " << "student two" << endl;
	fig = (s1 >= s2) ? "" : "not";
	cout << "Student one is " << fig << " >= " << "student two" << endl;
	fig = (s1 <= s2) ? "" : "not";
	cout << "Student one is " << fig << " <= " << "student two" << endl;
	fig = (s1 != s2) ? "" : "not";
	cout << "Student one is " << fig << " != " << "student two" << endl;

	system("pause");
	return 0;
}

