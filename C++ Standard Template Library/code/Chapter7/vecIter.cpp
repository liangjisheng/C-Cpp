
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	vector<int> coll;

	// insert some elements
	for (int i = 9; i >= 0; --i)
		coll.push_back(i);

	// print
	cout << "before sort" << endl;
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// ���vector�ĵ�������ʵ��Ϊָ�룬��δ����벻ͨ����C++�������޸��κλ���
	// ����(����ָ��)����ʱֵ��������struct��class�����������������ʵ��Ϊclass
	// ����Ա���ͨ����deque,list,sets,maps���ܱ���ͨ������Ϊ���ǵĵ�����������
	// ��ʵ��Ϊһ��ָ��
	// ����һ��Ԫ���������Ԫ������
	if (coll.size() > 1)
		sort(++coll.begin(), coll.end());

	// print
	cout << "after sort" << endl;
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}