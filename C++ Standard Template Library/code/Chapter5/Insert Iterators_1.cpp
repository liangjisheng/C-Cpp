
// �������������ĵ�һ��������insert iterator,���Ϊinserts
// inserts����ʹ�㷨�Բ���(insert)��ʽ���Ǹ�д(overwrite)
// ��ʽʹ��,ʹ��insert���Խ��Ŀ��ռ䲻������,��ʹ��Ŀ��
// �ռ�Ĵ�С����Ҫ�ɳ�

#include <iostream>
#include <vector>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;


int main()
{
	list<int> coll1;
	list<int>::iterator iter1;

	for (int i = 1; i <= 9; ++i)
		coll1.push_back(i);

	cout << "coll1: ";
	for (iter1 = coll1.begin(); iter1 != coll1.end(); ++iter1)
		cout << *iter1 << ' ';
	cout << endl;

	// copy the elements of coll1 into coll2 by appending them
	vector<int> coll2;
	vector<int>::iterator iter2;

	// back inserts���ڲ�����push_back(),������β�˲���Ԫ��
	// ������������3��:vector,list,deque
	copy(coll1.begin(), coll1.end(),		// source
			back_inserter(coll2));			// destination

	cout << "coll2: ";
	for (iter2 = coll2.begin(); iter2 != coll2.end(); ++iter2)
		cout << *iter2 << ' ';
	cout << endl;

	// copy the elements of coll1 into coll3 by inserting them at
	// the front - reverses the order of the elements
	deque<int> coll3;
	deque<int>::iterator iter3;

	// front inserts���ڲ�����push_front(),��Ԫ�ز���Ԫ����ǰ��
	// ������������list,deque
	copy(coll1.begin(), coll1.end(),		// source
			front_inserter(coll3));			// destination

	cout << "coll3: ";
	for (iter3 = coll3.begin(); iter3 != coll3.end(); ++iter3)
		cout << *iter3 << ' ';
	cout << endl;

	// copy elements of coll1 into coll4
	// - only inserter that works for associative collections
	set<int> coll4;
	set<int>::iterator iter4;

	// inserts�ڲ����ó�Ա����insert(),������ֵ����λ����Ϊ����
	// STL�������ṩ��insert()��Ա����,����Ψһ�����ڹ���ʽ����
	// ���ϵ�һ��Ԥ�ȶ���õ�inserter.�ڹ���ʽ������,����ʱ����
	// ����λ��ֻ��һ����ʾ,������ȷ����ʲô�ط���ʼ��Ѱ��ȷ��
	// ����λ��,�������ȷ,Ч���ϵı��ֻ��û����ʾ�����
	copy(coll1.begin(), coll1.end(),			// source
			inserter(coll4, coll4.begin()));	// destination

	cout << "coll4: ";
	for (iter4 = coll4.begin(); iter4 != coll4.end(); ++iter4)
		cout << *iter4 << ' ';
	cout << endl;

	system("pause");
	return 0;
}

