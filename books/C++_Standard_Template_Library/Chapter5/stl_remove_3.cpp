
// ��Щ���Ƴ�remove,����resort,�޸�modifyԪ�ص��㷨�������ڹ���ʽ����
// ����.�����Щ�㷨���ڹ���ʽ��������,��ı�ĳλ���ϵ�ֵ,�����ƻ���
// ����(sorted)����,�Ǿ��ƻ��˹���ʽ�����Ļ���ԭ��: �����ڵ�Ԫ������
// ����ĳ������׼���Զ�����.���,Ϊ�˱�֤���ԭ��,����ʽ���������е�
// ������������Ϊָ����.ֻ��ʹ�ù���ʽ�����ĳ�Ա������ɾ��Ԫ��

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;


int main()
{
	set<int> coll;

	for (int i = 1; i <= 9; ++i)
		coll.insert(i);

	// print all elements of the collection
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// remove all elements with value 3
	// - algorithm remove() does not work
	// - instead member function erase() works
	// ����ɾ��Ԫ�صĸ���,�ڽ�ֹ�ظ���������set,map
	// �䷵��ֵֻ����0��1
	int num = coll.erase(3);

	cout << "number of removed elements: " << num << endl;

	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}