
#include <iostream>
#include <list>			// 在头文件list中声明，在std中实现

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
		// pop_front()并不会返回被删除的元素
		coll.pop_front();
	}
	cout << endl;

	system("pause");
	return 0;
}