
// ����������������ȵ�Ԫ��
// ����[beg, end)�е�һ��"�����������Ԫ��"֮�еĵ�һԪ��λ��
// InputIterator adjacent_find(InputIterator beg, InputIterator end);
// ʹ�ö�Ԫ�ж�ʽΪtrue�ĵ�һԪ��λ��
// InputIterator adjacent_find(InputIterator beg, InputIterator end, BinaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;

// return whether the second object has double the value of the first
bool doubled(int elem1, int elem2) { return elem1 * 2 == elem2; }


int main()
{
	vector<int> coll;
	coll.push_back(1);
	coll.push_back(3);
	coll.push_back(2);
	coll.push_back(4);
	coll.push_back(5);
	coll.push_back(5);
	coll.push_back(0);

	PRINT_ELEMENTS(coll, "coll: ");

	// search first two elements with equal value
	vector<int>::iterator pos(coll.end());
	pos = adjacent_find(coll.begin(), coll.end());

	if (pos != coll.end())
		cout << "first two elements with equal value have position "
			<< distance(coll.begin(), pos) + 1 << endl;

	// search first tow elements for which the second has double the value of the first
	pos = adjacent_find(coll.begin(), coll.end(), doubled);

	if (pos != coll.end())
		cout << "first two element with second value twice the first have pos."
			<< distance(coll.begin(), pos) + 1 << endl;

	system("pause");
	return 0;
}