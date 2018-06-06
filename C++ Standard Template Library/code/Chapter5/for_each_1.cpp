
// 一些算法可以接受用户定义的辅助性函数,由此提供其灵活性和能力
// 这些函数将在算法内部被调用

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// function that prints the passed argument
void print(int elem) { std::cout << elem << ' '; }


int main()
{
	vector<int> coll;

	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);

	// for_each()对区间内的每一个元素调用print函数
	// 每个元素作为参数传入print
	for_each(coll.begin(), coll.end(),	// range
		print);							// operation
	cout << endl;

	system("pause");
	return 0;
}