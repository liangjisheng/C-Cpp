
// �ӱ�׼�����ȡ�ַ�������������Ȼ���ӡ����Ԫ��(ȥ���ظ��ַ���)
// Ctrl+Z�������

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

int main()
{
	cout << "input some word: " << endl;

	/* create a string set
	 * initialized by all words from standard input
	*/
	set<string> coll((istream_iterator<string>(cin)),
		(istream_iterator<string>()));

	// print all elements
	copy(coll.begin(), coll.end(),
			ostream_iterator<string>(cout, "\n"));

	system("pause");
	return 0;
}