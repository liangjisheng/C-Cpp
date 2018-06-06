
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Student
{
	char *StudentName;
public:
	Student(char *n)
	{
		int len = strlen(n);
		len = (len > 10) ? len : 10;
		StudentName = new char[len + 1];
		memset(StudentName, 0, len + 1);
		strcpy(StudentName, n);
	}
	~Student()
	{
		delete []StudentName;
		StudentName = NULL;
		cout << "StudentName has been deleted" << endl;
	}
};


class CollegeStudent : public Student
{
	char *CollegeName;
public:
	CollegeStudent(char *n1, char *n2) : Student(n1)
	{
		int len = strlen(n2);
		len = (len > 10) ? len : 10;
		CollegeName = new char[len + 1];
		memset(CollegeName, 0, len + 1);
		strcpy(CollegeName, n2);
	}
	~CollegeStudent()
	{
		delete []CollegeName;
		CollegeName = NULL;
		cout << "CollegeName has been deleted" << endl;
	}
};


int main()
{
	// 如果析构函数不是虚函数，在涉及到内存分配时，如果使用基类的指针释放实际
	// 上是派生类对象的话可能会造成内存泄露
	Student *p = new CollegeStudent("li", "shanxi");
	delete p;
	cout << endl;

	CollegeStudent *p1 = new CollegeStudent("li", "shanxi");
	delete p1;

	system("pause");
	return 0;
}