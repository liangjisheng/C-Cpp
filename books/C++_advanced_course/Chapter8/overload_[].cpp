
// []是C++中的下标运算符,对于数组或者指针来说，下标运算符的语义是确定的
// 不能够进行重载，C++规定:[]只能作为类的成员函数进行重载

#include <iostream>
#include <string>

using namespace std;

class A
{
	int num[3];
public:
	A();
	int& operator[](int);
};

A::A()
{
	num[0] = 0;
	num[1] = 1;
	num[2] = 2;
}

// 返回类型为引用类型,这是与传统的数组下标运算保持一致的做法
// 通过下标找到特定的数组元素后,既能读,也能写
int& A::operator[](int sub)
{
	if(sub < 0 || sub > 2)
		throw sub;
	else
		return num[sub];
}


// 一般来说，下标的数据类型是整型，这是C/C++语言中下标的基本用法，但从
// 语法的角度来说，对operator[]操作符进行重载，并没有限定下标的数据类型
// 这样在某些特殊情况下，可以采用特殊的数据类型的下标
class Empolyee
{
	string name;
	string position;
public:
	Empolyee(string, string);
	string& operator[](string);
};

Empolyee::Empolyee(string n, string p)
{
	name = n;
	position = p;
}

// operator[]只接受一个参数,没有参数或者多于一个参数都会造成编译错误
// 参数的类型可以是包括int在内的任意类型,应该是返回引用类型,这样既能
// 读又能写
string& Empolyee::operator[](string s)
{
	if(s == "name")
		return name;
	else if(s == "position")
		return position;
	throw s;
}


int main()
{
	//A a;
	//A *p = &a;
	//try{
	//	// 在表达式p[0][i]中,第一个[]运算符是下标运算符的愿意,p[0]相当于
	//	// *p,代表指针所指的对象,而第二个[]运算符使用的是重载后的语义,表
	//	// 示从对象内部的成员数组中取数据,当下标为3时,抛出异常
	//	for(int i = 0; i <= 4; i++)
	//		cout << p[0][i] << endl;
	//}
	//catch(int sub){
	//	cout << "Subscript out of range:" << sub << endl;
	//}

	Empolyee a("name1", "emp1"), b("name2", "emp2");
	try{
		cout << "A's name is: " << a["name"] << endl;
		cout << "A's position is: " << a["position"] << endl;
		cout << "B's name is: " << b["name"] << endl;
		cout << "B's position is: " << b["position"] << endl;
		cout << "B's address is: " << b["address"] << endl;
	}
	catch(string &s){
		cout << "Unknown attribute: " << s << endl;
	}

	system("pause");
	return 0;
}

