
// C++��׼������ṩ�����Ԥ����ķº���
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

// ���������(Function Adapters):�ܹ����º�������һ���º���(��ĳ��ֵ����ĳ��һ�㺯��)
// ��������ķº���

// find_if(coll.begin(), coll.end(), bind2nd(greater<int>(), 42));
// bind2nd(greater<int>(), 42)���ĳ��ֵ�Ƿ����42
// bind2nd()�ǽ�һ����Ԫ�º���greater<>ת��Ϊһ��һԪ�º�����ͨ�����ڶ�������������
// ��һ������ָ���Ķ�Ԫ�º�������Ϊ���ߵĵڶ������������������42��Ϊ�ڶ�������������
// greater<>

// ���������е�һ��ż��ֵԪ��
// pos = find_if(coll.begin(), coll.end(), not1(bind2nd(modulus<int>(), 2)));

// ��Գ�Ա��������Ƶĺ��������
// mem_fun_ref(op)		����op��op��ĳ�����һ��const��Ա����
// mem_fun(op)			����op��op��ĳ����ָ���һ��const��Ա����

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
	// ����������Ὣ���ĳ��Ԫ�صĺ�������ת��Ϊ������֮��Ա����
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
