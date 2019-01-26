
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	list<int> coll;

	for (int i = 1; i <= 6; ++i)
	{
		coll.push_front(i);
		coll.push_back(i);
	}

	// print all elements of the collection
	cout << "pre: ";
	copy(coll.begin(), coll.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	// remove all element with value 3
	// ��û��������ɾ��Ԫ��,���ǽ�3�����ֵ��ǰ��,��3���ǵ�
	// remove()����һ���µ��յ�,�������ø��յ���������,ɾ���������Ĵ�С
	// �����Ǳ�ɾ��Ԫ�صĸ���
	remove(coll.begin(), coll.end(), 3);

	cout << "post: ";
	copy(coll.begin(), coll.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}