
// ���ҵ�һ����ͬ��

// ���ص�һ����������Ķ�ӦԪ��
// pair<IInputIterator1, InputIterator2>
// mismatch(InputIterator1 beg, InputIterator1 end, InputIterator2 cmpBeg);
// pair<InputIterator1, InputIterator2>

// ����ʹ�ö�Ԫ�ж�ʽΪfalse�Ķ�ӦԪ��
// mismatch(InputIterator1 beg, InputIterator1 end,
//			InputIterator2 cmpBeg, BinaryPredicate op);

// ���û���ҵ�����㣬�ͷ���һ��pair����end�͵ڶ����еĶ�ӦԪ�����
// �Ⲣ����ζ������������ȣ���Ϊ�ڶ������п��ܰ����Ƚ϶��Ԫ��

#include "..\..\algostuff.hpp"
using namespace std;


int main()
{
	vector<int> coll1;
	list<int> coll2;

	INSERT_ELEMETNS(coll1, 1, 6);

	for (int i = 1; i <= 16; i *= 2)
		coll2.push_back(i);
	coll2.push_back(3);

	PRINT_ELEMENTS(coll1, "coll1: ");
	PRINT_ELEMENTS(coll2, "coll2: ");

	// find first mismatch
	pair<vector<int>::iterator, list<int>::iterator> values;
	values = mismatch(coll1.begin(), coll1.end(),	// first range
					coll2.begin());					// second range

	if (values.first == coll1.end())
		cout << "no mismatch" << endl;
	else
		cout << "fist mismatch: " << *values.first
			<< " and " << *values.second << endl;

	// find first position where the element of coll1 is not 
	// less than the corresponding element of coll2
	values = mismatch(coll1.begin(), coll1.end(),	// first range
					coll2.begin(),			// second range
					less_equal<int>());		// criterion

	if (values.first == coll1.end())
		cout << "always less-or-equal" << endl;
	else
		cout << "not less-or-equal: " << *values.first
			<< " and " << *values.second << endl;

	system("pause");
	return 0;
}