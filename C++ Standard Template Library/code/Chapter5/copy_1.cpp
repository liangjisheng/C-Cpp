
// �����stl��ĳ���㷨����������,��ô�����������,���ȷ���ڶ�(�Լ�����)
// ������ӵ�е�Ԫ�ظ���,���ٺ͵�һ�����ڵ�Ԫ�ظ�����ͬ,�ر���ִ��Ϳд����
// ���ȷ��Ŀ������(destination ranges)����

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> coll1;
	vector<int> coll2;

	for (int i = 1; i <= 9; ++i)
		coll1.push_back(i);

	// Runtime error
	// overwrites nonexisting elements in the destination
	// Ŀ����������Ϊ��,û���㹻��Ԫ�ع���д
	// Ҫ�����1.ȷ��Ŀ���������㹻�Ŀռ�,2����insert iterator
	copy(coll1.begin(), coll1.end(),		// soruce
			coll2.begin());					// destination

	system("pause");
	return 0;
}
