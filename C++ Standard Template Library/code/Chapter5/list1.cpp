
#include <iostream>
#include <list>			// ��ͷ�ļ�list����������std��ʵ��

using std::cout;
using std::endl;
using std::list;

int main()
{
	list<char> coll;

	// append elements from 'a' to 'z'
	for (char c = 'a'; c <= 'z'; ++c)
		coll.push_back(c);

	/* print all elements 
	 * while there are elements
	 * print and remove the first element
	*/

	while(!coll.empty())
	{
		cout << coll.front() << ' ';
		// pop_front()�����᷵�ر�ɾ����Ԫ��
		coll.pop_front();
	}
	cout << endl;

	system("pause");
	return 0;
}