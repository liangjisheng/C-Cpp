
// Ҳ���Խ����������ת��Ϊ����������������������ṩ��һ��base()��Ա����
// iterator base() const;
// �����������������������໥ת����ʵ��λ��(��������ָԪ��)ά�ֲ������仯����
// �߼�λ��(��������ָ����ֵ)

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> coll;

	// insert elements
	for (int i = 0; i < 10; ++i)
		coll.push_back(i);

	list<int>::iterator pos;
	pos = find(coll.begin(), coll.end(), 5);

	// print value of the element
	cout << "pos: " << *pos << endl;

	// convert iterator to reverse iterator
	list<int>::reverse_iterator rpos(pos);

	// print value of the element to which the reverse iterator refers
	cout << "rpos: " << *rpos << endl;

	// convert reverse iterator back to normal iterator
	list<int>::iterator rrpos;
	rrpos = rpos.base();

	// print value of the element to which the normal iterator refers
	cout << "rrpos: " << *rrpos << endl;

	system("pause");
	return 0;
}