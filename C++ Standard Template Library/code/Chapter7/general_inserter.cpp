
// General inserter���Ϊ(General insert iterator)��������������ʼ��(1):����,(2)�����λ��
// �������ڲ��Դ�����λ��Ϊ���������ó�Ա����insert(),
// inserter()���ṩ�˸�������ֶ�������general inserter����ʼ��
// general inserter�����б�׼������ʹ�ã�ӦΪ���б�׼�������ṩ��insert(),�Թ�����������
// (sets,maps)������λ��ֻ�Ǹ���ʾ
// general inserter���ظոձ�������Ǹ�Ԫ�ص�λ�ã�����Ϊ��ȷ���õ�������λ��ʼ����Ч
// ��Ϊÿһ�β����������(���ٿ��ܻ�)ʹ��ָ�����������е�����ʧЧ

#include <iostream>
#include <set>
#include <list>
#include <algorithm>
#include <iterator>
#include "..\..\print.hpp"

using namespace std;


int main()
{
	set<int> coll;

	// create insert iterator for coll
	// inconvenient way
	insert_iterator<set<int> > iter(coll, coll.begin());

	// insert elements with the usual iterator interface
	*iter = 1;
	// iter++;
	*iter = 2;
	// iter++;
	*iter = 3;

	PRINT_ELEMENTS(coll);

	// create inserter and insert elements
	// convenient way
	inserter(coll, coll.end()) = 44;
	inserter(coll, coll.end()) = 55;

	PRINT_ELEMENTS(coll);

	// use inserter to insert all elements into a list
	list<int> coll2;
	copy(coll.begin(), coll.end(),			// source
		inserter(coll2, coll2.begin()));	// destination

	PRINT_ELEMENTS(coll2, "list: ");

	// use inserter to reinsert all elements into the list before the second element
	copy(coll.begin(), coll.end(),			// source
		inserter(coll2, ++coll2.begin()));	// destination

	PRINT_ELEMENTS(coll2, "list: ");

	system("pause");
	return 0;
}
