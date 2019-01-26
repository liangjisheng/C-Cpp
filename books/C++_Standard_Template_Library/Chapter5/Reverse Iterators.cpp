
// ������Ԥ����ĵ����������(iterator adapters)����reverse iterators
// ��Increment(����)����ת��Ϊdecrement(�ݼ�)����,��֮��Ȼ

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


int main()
{
	vector<int> coll;

	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);

	cout << "Positive: ";
	copy(coll.begin(), coll.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "Reverse: ";
	// rbegin()ָ�����һ��Ԫ��,rend()ָ���һ��Ԫ�ص�ǰһ��Ԫ��
	// rend()λ���ϲ�û�кϷ�Ԫ��,����ʹ��operator*��operator->
	// ����ᵼ��δ������Ϊ
	copy(coll.rbegin(), coll.rend(),		// source
		ostream_iterator<int>(cout, " "));	// destination
	cout << endl;

	system("pause");
	return 0;
}