
// 定义了一个枚举类型之后，相当于提供了若干代表整数的符号常量
#include <iostream>

using std::cout;
using std::endl;

enum weekDay{ Sun, Mon, Tue, Wed, Thu, Fri, Sat };

// 在一个作用域内可以定义多个枚举类型，允许两个枚举常量对应相同的整数值，
// 但不允许任何两个枚举常量同名，否则会出现编译错误，下面一行的代码会造成
// 编译错误。如果仅仅是想使用枚举常量，而并不需要定义枚举变量，则在定义
// 枚举类型时枚举类型名也可以省略
// enum weekDay1{ Sun, Mon, Tue, Wed, Thu, Fri, Sat };


void test()
{
	weekDay day;
	cout << Sun << " " << Mon << " " << Tue << " " << Wed << " "
		<< Thu << " " << Fri << " " << Sat << endl;

	// 只能将枚举常量赋给它，而不能直接将整数值赋给它，在输出时，
	// 直接输出它的值所对应的整数值
	day = Sat;
	cout << day << endl;
	cout << sizeof(weekDay) << endl;
	cout << sizeof(day) << endl;
}


// 枚举常量的作用类似于类中的静态整型常变量，但要注意他们只是符号常量，
// 是不可寻址的，在编译阶段就已经替换为相应的整数值

class someclass
{
public:
	static const int coint = 4;
	enum weekDay{ Mon = 2, Tue, Wed, Thu = 100, Fri, Sat, Sun };
	// 将int[7]类型重定义为intarray
	typedef int intarray[7];
	someclass() { memset(this, 0, sizeof(someclass)); }

	intarray ia;
};


void test_1()
{
	someclass sc;
	cout << someclass::coint << endl;
	cout << someclass::Mon << " " << someclass::Tue << " "
		<< someclass::Wed << " " << someclass::Thu << " "
		<< someclass::Fri << " " << someclass::Sat << " "
		<< someclass::Sun << endl;

	for(int i = 0; i < 7; i++)
		cout << sc.ia[i] << " ";
	cout << endl;
	cout << endl;

	someclass::intarray ia;
	ia[0] = someclass::Mon;
	ia[1] = someclass::Tue;
	ia[2] = someclass::Wed;
	ia[3] = someclass::Thu;
	ia[4] = someclass::Fri;
	ia[5] = someclass::Sat;
	ia[6] = someclass::Sun;
	
	for(int i = 0; i < 7; i++)
		cout << ia[i] << " ";
	cout << endl;

	cout << someclass::coint << endl;
}


int main()
{
	// test();
	test_1();

	system("pause");
	return 0;
}