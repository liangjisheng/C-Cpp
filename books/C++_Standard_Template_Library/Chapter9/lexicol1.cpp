
// ����С��
// �ж�����[beg1, end1)��Ԫ���Ƿ�С������[beg2, end2)��Ԫ�أ���νС����
// ָ�ֵ�(lexicographical)˳�������
// �����������е�Ԫ��һһ�Ƚϣ�ֱ���������������
// �����Ԫ�ز���ȣ���������Ԫ�صıȽϽ���������������еıȽϽ��
// ����������е�Ԫ��������ͬ����Ԫ�ؽ��ٵ��Ǹ�����С����һ���У��������
// ��һ���е�Ԫ���������٣��ȽϽ����true
// ����������ж�û�и����Ԫ�ؿ����Ƚϣ���������������ȣ������ȽϽ����false

// bool lexicographical_compare(InputIterator1 beg1, InputIterator1 end1,
//								InputIterator2 beg2, InputIterator2 end2);

// bool lexicographical_compare(InputIterator1 beg1, InputIterator1 end1,
//								InputIterator2 beg2, InputIterator2 end2,
//								CompFunc op);

#include "..\..\algostuff.hpp"
using namespace std;

void pritnCollection(const list<int>& l) { PRINT_ELEMENTS(l); }

bool lessForCollection(const list<int>& l1, const list<int>& l2)
{
	return lexicographical_compare(
		l1.begin(), l1.end(),	// first range
		l2.begin(), l2.end());	// second range
}


int main()
{
	list<int> c1, c2, c3, c4;

	// fill all collections with the same starting values
	INSERT_ELEMETNS(c1, 1, 5);
	c4 = c3 = c2 = c1;

	// and now some differences
	c1.push_back(7);
	c3.push_back(2);
	c3.push_back(0);
	c4.push_back(2);

	// create collection of collections
	vector<list<int> > cc;

	cc.push_back(c1);
	cc.push_back(c2);
	cc.push_back(c3);
	cc.push_back(c4);
	cc.push_back(c3);
	cc.push_back(c1);
	cc.push_back(c4);
	cc.push_back(c2);

	// print all collections
	for_each(cc.begin(), cc.end(), pritnCollection);
	cout << endl;

	// sort collection lexicographically
	sort(cc.begin(), cc.end(), lessForCollection);

	// print all collections
	for_each(cc.begin(), cc.end(), pritnCollection);

	system("pause");
	return 0;
}