
// �ӱ�׼�����ȡ�ַ�������������Ȼ���ӡ����Ԫ��(ȥ���ظ��ַ���)
// Ctrl+Z�������

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	cout << " input some words: " << endl;

	/* create a string vector
	 * initialized by all words from stardard input
	*/
	vector<string> coll1((istream_iterator<string>(cin)),
			(istream_iterator<string>()));

	// print all elements ignoring subsequent duplicates
	cout << endl;
	unique_copy(coll1.begin(), coll1.end(), 
		ostream_iterator<string>(cout, "\n"));

	// sort element
	sort(coll1.begin(), coll1.end());

	// print all elements ignoring subsequent duplicates
	cout << endl;
	unique_copy(coll1.begin(), coll1.end(), 
		ostream_iterator<string>(cout, "\n"));

	system("pause");
	return 0;
}