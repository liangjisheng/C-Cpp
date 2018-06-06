
// 如果用stl的某个算法处理多个区间,那么当你调用它是,务必确保第二(以及其他)
// 区间所拥有的元素个数,至少和第一区间内的元素个数相同,特别是执行涂写动作
// 务必确保目标区间(destination ranges)够大

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> coll1;
	vector<int> coll2;

	for (int i = 1; i <= 9; ++i)
		coll1.push_back(i);

	// Runtime error
	// overwrites nonexisting elements in the destination
	// 目标区间现在为空,没有足够的元素供覆写
	// 要想避免1.确保目标区间有足够的空间,2采用insert iterator
	copy(coll1.begin(), coll1.end(),		// soruce
			coll2.begin());					// destination

	system("pause");
	return 0;
}
