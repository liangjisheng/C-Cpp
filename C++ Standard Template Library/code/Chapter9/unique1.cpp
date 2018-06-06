
// �Ƴ������ظ�Ԫ��
// ������[beg, end)��������ǰһԪ����ȵ�Ԫ���Ƴ�
// ���ر��䶯����������յ�(�߼��յ㣬Ҳ�������һ��δ���Ƴ���Ԫ�ص���һ��λ��)
// ForwardIterator unique(ForwardIterator beg, ForwardIterator end);

// ��ÿһ��λ��Ԫ��e֮�����Ƕ�Ԫ�ж�ʽop(elem, e)Ϊtrue������elemԪ���Ƴ�
// ForwardIterator unique(ForwardIterator beg, ForwardIterator end, BinaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	// source data
	int source[] = { 1, 4, 4, 6, 1, 2, 2, 3, 1, 6, 6, 6, 5, 7, 5, 4, 4 };
	int sourceNum = sizeof(source) / sizeof(source[0]);

	list<int> coll;
	// initialize coll with elements from source
	copy(source, source + sourceNum,
		back_inserter(coll));
	PRINT_ELEMENTS(coll);

	// remove consecutive duplicates
	list<int>::iterator pos;
	pos = unique(coll.begin(), coll.end());

	// print elements not removed
	// use new logical end
	copy(coll.begin(), pos,
		ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	// reinitialize coll with elements from source
	copy(source, source + sourceNum,
		coll.begin());
	PRINT_ELEMENTS(coll);

	// remove elements if there was a previous greater element
	coll.erase(unique(coll.begin(), coll.end(), greater<int>()), coll.end());
	PRINT_ELEMENTS(coll);

	system("pause");
	return 0;
}