
// ���ҵ�һ�������һ������λ��
// pair<ForwardIterator, ForwardIterator>
// equal_range(ForwardIterator beg, ForwardIterator end, const T& value);
// pair<ForwardIterator, ForwardIterator>
// equal_range(ForwardIterator beg, ForwardIterator end, const T& value,
//				BinaryPredicate op);
// ����ֵ����ʽ��Чmake_pair(lower_bound(), upper_bound());

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	list<int> coll;

	INSERT_ELEMETNS(coll, 1, 9);
	INSERT_ELEMETNS(coll, 1, 9);
	coll.sort();
	PRINT_ELEMENTS(coll);

	// print first and last position 5 could get inserted
	pair<list<int>::iterator, list<int>::iterator> range;

	range = equal_range(coll.begin(), coll.end(), 5);

	cout << "5 could get position "
		<< distance(coll.begin(), range.first) + 1
		<< " up to "
		<< distance(coll.begin(), range.second) + 1
		<< " without breaking the sorting" << endl;

	system("pause");
	return 0;
}