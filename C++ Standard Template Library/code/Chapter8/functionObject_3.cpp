
// ��ν�ж�ʽ(Predicates)���Ƿ���bool(��ת��Ϊbool)��һ��������º���
// ��STL���ԣ��������з���boolֵ�ĺ������ǺϷ����ж�ʽ

#include <iostream>
#include <list>
#include <algorithm>
#include "..\..\print.hpp"

using namespace std;

// function object that return true for the nth call
// ����n�α�����ʱ����true
class Nth
{
private:
	int nth;	// call for which to return value
	int count;	// call counter
public:
	Nth(int n) : nth(n), count(0) {}

	bool operator() (int) { return ++count == nth; }
};


int main()
{
	list<int> coll;

	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);
	PRINT_ELEMENTS(coll);

	// remove third element
	list<int>::iterator pos;
	pos = remove_if(coll.begin(), coll.end(),	// range
					Nth(3));					// remove criterion
	coll.erase(pos, coll.end());

	// ��������ѵ�3��Ԫ��ɾ���ˣ���ʵ���ϵ�3���͵�6��Ԫ�ض�ɾ���ˣ�
	// ��Ϊremove_if()�����ڲ��ᱣ���ж�ʽ��һ�ݸ���
	PRINT_ELEMENTS(coll);

	system("pause");
	return 0;
}