
// C++Ϊ�������ṩ��3����������advance(),distance()��iter_swap()
// ǰ������Ϊ�������͵ĵ������ṩ��ԭ��ֻ��Random Access���������е�������ǰ��(����)���Ԫ��
// �����������֮��ľ��롣��������������������������ֵ
// void advance(InputIterator& pos, Dist n);

// ʹ��advance()����һ�����Ӿ��Ǻ���"��������������(input stream)�ж�����ĳЩ����"

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> coll;

	// insert some elements
	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);

	list<int>::iterator pos = coll.begin();

	// print actual element
	cout << *pos << endl;

	// step three elements forward
	advance(pos, 3);

	// print actual element
	cout << *pos << endl;

	// step one element backward
	advance(pos, -1);

	// print actual element
	cout << *pos << endl;

	system("pause");
	return 0;
}