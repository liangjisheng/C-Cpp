
// 可以将一般迭代器转换为一个reverse迭代器，转换前后迭代器的逻辑位置发生了变化

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