
// �Ƴ����㷨(Removing Algorithms)
// ����Ԫ��ֵ��ĳ��׼����һ���������Ƴ�ĳЩԪ�أ���Щ�㷨�����ܸı�Ԫ�ص�����
// ����ֻ��һ�߼��ϵ�˼������ԭ�����ں���Ĳ��Ƴ�Ԫ����ǰ�ƶ���������Щ���Ƴ�Ԫ��
// ���ѡ����Ƕ�������������߼��յ�(Ҳ�������һ�����Ƴ�Ԫ�ص���һλ��)

// ForwardIterator remove(ForwardIterator beg, ForwardIterator end, const T& value);
// ForwardIterator remove_if(ForwardIterator beg, ForwardIterator end, UnaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;


int main()
{
	vector<int> coll;
	INSERT_ELEMETNS(coll, 2, 6);
	INSERT_ELEMETNS(coll, 4, 9);
	INSERT_ELEMETNS(coll, 1, 7);
	PRINT_ELEMENTS(coll, "coll: ");

	// remove all elements with value 5
	vector<int>::iterator pos;
	pos = remove(coll.begin(), coll.end(), 5);
	PRINT_ELEMENTS(coll, "size not changed: ");

	// erase the removed elements in the container
	coll.erase(pos, coll.end());
	PRINT_ELEMENTS(coll, "size changed: ");

	// remove all elements less than 4
	coll.erase(remove_if(coll.begin(), coll.end(),
				bind2nd(less<int>(), 4)), coll.end());
	PRINT_ELEMENTS(coll, "<4 removed: ");

	system("pause");
	return 0;
}