
// ���������������ʹ��ĳ���㷨,��Ҳδ�ؾ�һ���Ǻ�,������������ṩ
// �������ƶ����ܸ��ѵĳ�Ա����
// �����list����remove()ʱ,�㷨������֪����������list����,��Ϊ��
// ����������������ͬ�Ĺ���,�ı�Ԫ��ֵ,��������Ԫ�ص�λ��,ʵ���ϲ���
// ����ɾ��Ԫ��,ֻ��ʹ�ú����Ԫ�ظ���Ҫɾ����Ԫ��
// ���ʹ�ó�Ա����ɾ��,��Щ��Ա�������ɾ����Ԫ��,��������remove()��
// ���������ƶ���Ԫ��,��Ϊ��Ա�����˽�������ϸ��

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

// �����Ҫʹ�ô������Ч�ʵĻ�,Ӧ����Զ����ʹ�ó�Ա����.ǰ���Ǳ���
// ֪��ĳ������ȷʵ������Ч��������ͻ���ų�Ա����


int main()
{
	list<int> coll;

	for (int i = 1; i <= 6; ++i)
	{
		coll.push_front(i);
		coll.push_back(i);
	}

	cout << "Before: " << endl;
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// remove all elements with value 3
	// - poor performance
	coll.erase(remove(coll.begin(), coll.end(), 3), coll.end());

	cout << "poor performance remove(): " << endl;
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// remove all elements with value 4
	// - good performance
	coll.remove(4);

	cout << "good performance erase(): " << endl;
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}