
// ������ɸ�ֵ�Ƿ����
// ������ʽ�������ж���������[beg, end)�Ƿ������һ����������[searchBeg, searchEnd)
// ��ȫ��Ԫ�ء�����[searchBeg, searchEnd)�е�ÿһ��Ԫ�أ����[beg, end)����һ����Ӧ
// ���൱Ԫ�أ���ô[searchBeg, searchEnd)�϶���[beg, end)���Ӽ�
// �����㷨֮ǰ������ȷ���������Ѿ�������ͬ������׼���ĺ�����
// bool includes(InputIterator1 beg, InputIterator end,
//				InputIterator2 searchBeg, InputIterator2 searchEnd);
// bool includes(InputIterator1 beg, InputIterator end,
//				InputIterator2 searchBeg, InputIterator2 searchEnd, BinaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	list<int> coll;
	vector<int> search;
	
	INSERT_ELEMETNS(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll: ");

	search.push_back(3);
	search.push_back(4);
	search.push_back(7);
	PRINT_ELEMENTS(search, "search: ");

	// check whether all elements in search are also in coll
	if (includes(coll.begin(), coll.end(), search.begin(), search.end()))
		cout << "all element of search are also in coll" << endl;
	else
		cout << "not all element of search are also in coll" <<endl;
	system("pause");
	return 0;
}