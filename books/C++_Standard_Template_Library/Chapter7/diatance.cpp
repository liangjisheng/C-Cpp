
// ��������������֮��ľ���
// Dist diatance(InputIterator pos1, InputIterator pos2);

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> coll;

	for (int i = -3; i <= 9; ++i)
		coll.push_back(i);

	// search element with value 5
	list<int>::iterator pos;
	pos = find(coll.begin(), coll.end(), 5);

	if (pos != coll.end())
	{
		// process and print difference from the beginning
		// distance�ĵ�һ�����������Բ���λ�ڵڶ���������֮�󣬷���ᵼ��δ������Ϊ
		// �����֪���Ǹ���ǰ���Ǹ��ں󣬱����ȼ��������������ֱ�ָ�������ľ���
		// ��������������ָ����ͬ��Ŀ������
		cout << "difference between beginning and 5: "
			<< distance(coll.begin(), pos) << endl;
	}
	else
		cout << "5 not found" << endl;

	system("pause");
	return 0;
}