
// Back inserters ���Ϊ(back insert iterator)ͨ����Ա��������һ��Ԫ��ֵ׷��������β��
// ����push_back()ֻ������vectors, deques, lists, strings֮�У�����C++��׼����Ҳֻ����Щ
// ����֧�� back inserters
// back inserter ����ʱ��������������������г�ʼ��������ʹ�� back_inserter();

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "..\..\print.hpp"

using namespace std;


int main()
{
	vector<int> coll;

	// create back inserter for coll: inconvenient(�������) way
	// ����������������������в�ͬ�ĳ�Ա����������insert��������ʼ��ʱһ��
	// Ҫ���֪���Լ���������������һ��
	back_insert_iterator<vector<int> > iter(coll);

	// insert elements with the usual iterator interface
	// ����������ĸ�ֵ���൱�ڲ��룬iter++��û��ʵ�ʲ�����ֻ�Ǽ򵥵Ĵ���iter
	// ����ע�ͻ��߲�ע��iter++�Բ��벢û��ʲôӰ��
	*iter = 1;
	//iter++;
	*iter = 2;
	//iter++;
	*iter = 3;

	PRINT_ELEMENTS(coll);

	// create back inserter and insert elements : convenient(�����) way
	back_inserter(coll) = 44;
	back_inserter(coll) = 55;

	PRINT_ELEMENTS(coll);

	// use back inserter to append all elements again
	// reserve enough memory to avoid reallocation
	coll.reserve(2 * coll.size());
	copy(coll.begin(), coll.end(),	// source
		back_inserter((coll)));		// destination

	PRINT_ELEMENTS(coll);

	system("pause");
	return 0;
}
