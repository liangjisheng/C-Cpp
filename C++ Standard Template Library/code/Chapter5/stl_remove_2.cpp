
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

// remove()�㷨�ǲ����Լ�������Ӧ�����ĳ�Ա����,������STLΪ�˻�ȡ�����
// �������Ĵ���.ͨ��"�Ե�����Ϊ�ӿ�",STL�����ݽṹ���㷨���뿪��.Ȼ����
// ����ֻ������"������ĳһλ��"�ĳ���������.һ����˵,���������Լ�����
// ������һ����֪.�κ�"�Ե�������������Ԫ��"���㷨,������(�޷�)ͨ������
// �����������������ṩ���κγ�Ա����,�������ǲ��˽�����ϸ�ڵ�


int main()
{
	list<int> coll;

	for (int i = 1; i <= 6; ++i)
	{
		coll.push_back(i);
		coll.push_front(i);
	}

	// print all elements of the collection
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// remove all elements with value 3 
	// - retain new end
	// newend����������ɾ��֮����Ϊ�߼��ϵ����յ�
	list<int>::iterator newend = remove(coll.begin(), coll.end(), 3);

	copy(coll.begin(), newend, ostream_iterator<int>(cout, " "));
	cout << endl;

	// print number of resulting elements
	// distance()��������������֮��ľ���,������������������������
	// ���ֱ������operator-�������,����listֻ�ṩ˫�������
	cout << "number of removed elements: "
		<< distance(newend, coll.end()) << endl;

	// remove "removed" elements
	// ���������ɾ��Ԫ��,���������������Ӧ��Ա����
	coll.erase(newend, coll.end());

	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}