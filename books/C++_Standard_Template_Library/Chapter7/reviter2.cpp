
// ���Խ�һ�������ת��Ϊһ��reverse��������ת��ǰ����������߼�λ�÷����˱仯

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> coll;

	// insert elements
	for (int i = 0; i < 10; ++i)
		coll.push_back(i);

	// find position of element with value 5
	vector<int>::iterator pos;
	pos = find(coll.begin(), coll.end(), 5);

	if (pos != coll.end())
		cout << "pos: " << *pos << endl;

	// convert iterator to reverse iterator rpos
	vector<int>::reverse_iterator rpos(pos);

	cout << "rpos: " << *rpos << endl;

	system("pause");
	return 0;
}