
// �㷨��һ������ĸ�����������Predicates(�ж�ʽ).��νPredicates
// ���Ƿ���bool�ĺ���.ͨ��������ָ������׼��Ͳ���׼��.
// �������з���bool�ĺ�������Predicates,STLҪ��,�����ͬ��ֵ
// Predicates����ó���ͬ�Ľ��,���Ҫ����Щ"������ʱ,��ı��Լ�
// �ڲ�״̬"�ĺ����������
// Unary Predicates����Ψһ������ĳ������
// Binary predicates(��Ԫ�б�ʽ)�ĵ�����;��,�Ƚ������������ض�����

#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>		// for abs()

using namespace std;


// predicate,which returns whether an integer is a prime number
bool isPrime(int number)
{
	// ignore negative sign
	number = abs(number);

	// 0 and 1 are prime numbers
	if (0 == number || 1 == number)
		return true;

	// find divisor that divides without a remainder
	int divisor;
	for (divisor = number / 2; number % divisor != 0; --divisor) {}

	// if no divisor greater than 1 is found,it is a prime number
	return 1 == divisor;
}


int main()
{
	list<int> coll;

	for (int i = 24; i <= 30; ++i)
		coll.push_back(i);

	// search for prime number
	list<int>::iterator pos;
	// find_if()�㷨�ڸ���������Ѱ��ʹ"�������һԪ�ж�ʽ"������
	// Ϊtrue�ĵ�һ��Ԫ��,���ظ��������ڵĵ�һ������
	// ���������,����coll.end()
	pos = find_if(coll.begin(), coll.end(),		// range
					isPrime);					// predicate

	if(pos != coll.end())
		cout << *pos << " is first prime number found" << endl;
	else
		cout << "no prime number found" << endl;

	system("pause");
	return 0;
}