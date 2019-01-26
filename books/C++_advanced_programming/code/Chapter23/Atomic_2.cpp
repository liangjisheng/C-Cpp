
#include <iostream>
#include <atomic>

using std::cout;
using std::endl;
using std::atomic;


int main()
{
	atomic<int> value(10);
	cout << "value = " << value << endl;
	// 获取一个原子类型的当前值，将给定的递增值添加到
	// 这个原子值，然后返回未递增的值
	int fetched = value.fetch_add(4);
	cout << "Fetched = " << fetched << endl;
	cout << "value = " << value << endl;

	system("pause");
	return 0;
}