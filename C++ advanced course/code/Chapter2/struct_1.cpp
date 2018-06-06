
// 在C++中，结构是一种真正的数据类型，利用结构体定义变量时，不需要像在C语言
// 中那样带上struct关键字，或者先使用typedef struct structname structname的
// 方式进行声明，在结构体中默认的访问权限是public,
// 如果在struct中没有显示定义任何构造函数，那么结构变量可以像在C语言中那样用
// 花括号中顺序指明数据成员的值的办法进行初始化，

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

	// Student中有显示定义构造函数，所以不能像下面的这样给赋值
	// Student s1 = {18, 80};						// error
	A a1 = {10, 11};								// ok
	a1.show();

	system("pause");
	return 0;
}

