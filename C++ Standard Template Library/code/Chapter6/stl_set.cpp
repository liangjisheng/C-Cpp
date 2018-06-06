
// sets和multisets在元素快速查找方面有优化设计，所以提供了特殊的查找函数
// 查找是应优先使用成员函数，如此可以获得对数时间复杂度，而非STL算法的线性
// 时间复杂度
// count(elem)	返回元素值为elem的元素个数
// find(elem)	返回元素值为elem的第一个元素，如果找不到就返回end()
// lower_bound(elem)返回elem的第一个可插入位置，也就是元素值>=elem的第一个元素位置
// upper_bound(elem)返回elem的最后一个可插入位置，也就是元素值>elem的第一个元素位置
// equal_range(elem)返回elem可插入的第一个位置和最后一个位置，也就是元素值==elem的元素区间

#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> c;

	c.insert(1);
	c.insert(2);
	c.insert(4);
	c.insert(5);
	c.insert(6);

	cout << "lower_bound(3): " << *c.lower_bound(3) << endl;
	cout << "upper_bound(3): " << *c.upper_bound(3) << endl;
	cout << "equal_range(3): " << *c.equal_range(3).first << " " 
		<< *c.equal_range(3).second << endl;

	cout << endl;
	cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
	cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
	cout << "equal_range(5): " << *c.equal_range(5).first << " " 
		<< *c.equal_range(5).second << endl;

	cout << endl;
	cout << "lower_bound(1): " << *c.lower_bound(1) << endl;
	cout << "upper_bound(1): " << *c.upper_bound(1) << endl;
	cout << "equal_range(1): " << *c.equal_range(1).first << " " 
		<< *c.equal_range(1).second << endl;

	system("pause");
	return 0;
}