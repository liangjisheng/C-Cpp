
#include <iostream>

using std::cout;
using std::endl;

template<class T, int a>
class Array
{
	int size;
public:
	Array() : size(a) {}
	T val[a];
	T& operator[](int i) { return val[i]; }
	void show()
	{
		cout << "The elements of the array is: ";
		for(int i = 0; i < size; i++)
			cout << val[i] << " ";
		cout << endl;
	}
};


template<class T, int a>
class Student
{
	int age;
public:
	Student() : age(a) {}
	double score;
	void show() 
	{ cout << "The Student's age is:" << age 
	<< " and its score is: " << score << endl; }
};


template<class T, int a, template<class T, int a> class A >
class Container
{
public:
	A<T, a> entity;
	void show() { entity.show(); }
};

template<class T, int a, template<class, int> class A >
class Container1
{
public:
	A<T, a> entity;
	void show() { entity.show(); }
};


int main()
{
	Container<double, 3, Array> obj1;
	obj1.entity[0] = 1.1;
	obj1.entity[1] = 2.2;
	obj1.entity[2] = 3.3;
	obj1.show();

	Container<double, 18, Student> obj2;
	obj2.entity.score = 80;
	obj2.show();

	Container1<double, 18, Student> obj3;
	obj3.entity.score = 80;
	obj3.show();

	system("pause");
	return 0;
}

