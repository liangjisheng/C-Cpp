
// front inserter ͨ����Ա����push_front()��һ��Ԫ��ֵ��������ͷ��������ֻ��
// deque��list����push_front(),����C++��׼����Ҳֻ������������֧��front inserter
// front inserter ����ʱ��������������������г�ʼ��������ʹ��front_inserter();

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "..\..\print.hpp"

using namespace std;


int main()
{
	list<int> coll;

	// create front iterator for coll
	// inconvenient way
	front_insert_iterator<list<int> > iter(coll);

	// insert elements with the usual iterator interface
	// �� back inserter һ������û�� iter++ ��һ��
	*iter = 1;
	// iter++;
	*iter = 2;
	// iter++;
	*iter = 3;

	PRINT_ELEMENTS(coll);

	// create front inserter and insert elements
	// convenient way
	front_inserter(coll) = 44;
	front_inserter(coll) = 55;

	PRINT_ELEMENTS(coll);

	// use front inserter to insert all elements again
	copy(coll.begin(), coll.end(),		// source
		front_inserter(coll));			// destination

	PRINT_ELEMENTS(coll);

	system("pause");
	return 0;
}
