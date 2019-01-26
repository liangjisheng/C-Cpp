
// ���ݵ�n��Ԫ������
// ������ʽ��������[beg, end)�ڵ�Ԫ�ؽ�������ʹ��n��λ���ϵ�Ԫ�ؾ�λ
// Ҳ����˵��������λ��n֮ǰ��Ԫ�ض�С�ڵ�������������λ��n֮���Ԫ��
// �����ڵ��������������͵õ��˸���nλ���ϵ�Ԫ�طָ��������������
// void nth_element(RandomAccessIterator beg, RandomAccessIterator nth,
//					RandomAccessIterator end);
// void nth_element(RandomAccessIterator beg, RandomAccessIterator nth,
//					RandomAccessIterator end, BinaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	deque<int> coll;

	INSERT_ELEMETNS(coll, 3, 7);
	INSERT_ELEMETNS(coll, 2, 6);
	INSERT_ELEMETNS(coll, 1, 5);
	PRINT_ELEMENTS(coll);

	// extract the four lowest elements
	nth_element(coll.begin(),		// beginning of range
				coll.begin() + 3,	// element that should be sorted correctly
				coll.end());		// end of range

	// print them
	cout << "the four lowest elements are: ";
	copy(coll.begin(), coll.begin() + 4, ostream_iterator<int>(cout, " "));
	cout << endl;

	// extract the four highest elements
	nth_element(coll.begin(),		// beginning of range
				coll.end() - 4,		// element that should be sorted correctly
				coll.end());		// end of range

	// print them
	cout << "the four highest elements are: ";
	copy(coll.end() - 4, coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// extract the four highest elements (second version)
	nth_element(coll.begin(),		// beginning of range
				coll.begin() + 3,	// element that should be sorted correctly
				coll.end(),			// end of range
				greater<int>());	// sorting criterion

	// print them
	cout << "the four highest elements are: ";
	copy(coll.begin(), coll.begin() + 4, ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}