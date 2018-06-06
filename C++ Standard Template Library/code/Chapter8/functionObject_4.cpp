
// C++标准程序库提供了许多预定义的仿函数
// negate<type>()				-param
// plus<type>()					param1 + param2
// minus<type>()				param1 - param2
// multiplies<type>()			param1 * param2
// divides<type>()				param1 / param2
// modulus<type>()				param1 % param2
// equal_to<type>()				param1 == param2
// not_equal_to<type>()			param1 != param2
// less<type>()					param1 < param2
// greater<type>()				param1 > param2
// less_equal<type>()			param1 <= param2
// greater_equal<type>			param1 >= param2
// logical_not<type>()			!param
// logical_and<type>()			param1 && param2
// logical_or<type>()			param1 || param2

// 函数配接器(Function Adapters):能够将仿函数和另一个仿函数(或某个值，或某个一般函数)
// 结合起来的仿函数

// find_if(coll.begin(), coll.end(), bind2nd(greater<int>(), 42));
// bind2nd(greater<int>(), 42)检查某个值是否大于42
// bind2nd()是将一个二元仿函数greater<>转换为一个一元仿函数。通常将第二个参数传给由
// 第一个参数指出的二元仿函数，作为后者的第二参数。因此上面是以42作为第二个参数来调用
// greater<>

// 返回序列中第一个偶数值元素
// pos = find_if(coll.begin(), coll.end(), not1(bind2nd(modulus<int>(), 2)));

// 针对成员函数而设计的函数配接器
// mem_fun_ref(op)		调用op，op是某对象的一个const成员函数
// mem_fun(op)			调用op，op是某对象指针的一个const成员函数

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

class Person
{
private:
	string name;
public:
	Person(string strName = "") : name(strName) {}

	void print() const { cout << name << endl; }
	void printWithPrefix(string prefix) const { cout << prefix << name << endl; }
};

void foo(const vector<Person>& coll)
{
	// call member function print() for each element
	// 函数配接器会将针对某个元素的函数调用转化为被传递之成员函数
	for_each(coll.begin(), coll.end(), mem_fun_ref(&Person::print));
	cout << endl;

	// call member function printWithPrefix() for each element
	// "Person: " is passed as an argument to the member function
	for_each(coll.begin(), coll.end(), 
		bind2nd(mem_fun_ref(&Person::printWithPrefix), "Person: "));
}

void foo_ptr(const vector<Person*>& coll)
{
	// call member function print() for each referred object
	for_each(coll.begin(), coll.end(), mem_fun(&Person::print));
	cout << endl;

	// call member function printWithPrefix() for each element
	// "Person: " is passed as an argument to the member function
	for_each(coll.begin(), coll.end(), 
		bind2nd(mem_fun(&Person::printWithPrefix), "Person: "));
}


int main()
{
	vector<Person> vecPerson;
	vector<Person*> vecPersonPtr;

	for (int i = 0; i <= 10; ++i)
	{
		string str = "Person ";
		stringstream sstr;
		sstr << i;
		str = str + sstr.str();
		vecPerson.push_back(Person(str));

		vecPersonPtr.push_back(new Person(str));
	}

	foo(vecPerson);
	cout << endl;

	foo_ptr(vecPersonPtr);
	
	// delete
	for (size_t i = 0; i < vecPersonPtr.size(); ++i)
		delete vecPersonPtr[i];

	system("pause");
	return 0;
}
