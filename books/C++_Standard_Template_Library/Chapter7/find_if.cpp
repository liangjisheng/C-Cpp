
/***********************************************************
 * @brief: find_if
 * @author: Jisheng Liang
 * @email: 1294851990@qq.com
 * @date: 2017/12/20 15:32:34
 * @version: 1.0
 **********************************************************/


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// ν���жϺ���divbyfive:�ж�x�ܷ�5����
bool divbyfive(int x) { return x % 5 ? 0 : 1; }

int main()
{
	vector<int> coll;
	for (vector<int>::size_type i = 0; i != 20; ++i)
		coll.push_back((i + 1) * (i + 3));

	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	vector<int>::iterator iter;
	iter = find_if(coll.begin(), coll.end(), divbyfive);

	if (iter != coll.end())
	{
		cout << "��һ���ܱ�5������Ԫ��Ϊ: " << *iter << endl;
		cout << "Ԫ�ص�����λ��Ϊ: " << iter - coll.begin() << endl;
	}

	system("pause");
	return 0;
}