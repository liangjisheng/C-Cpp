
#include<iostream>
#include<string>
#include<set>
#include<unordered_set>

using std::cout;
using std::endl;
using std::set;
using std::unordered_set;
using std::string;

int main()
{
	// unordered_set的数据存储结构是哈希表的方式结构，在插入时不会自动排序
	unordered_set<int> unorder_set;
	unorder_set.insert(7);
	unorder_set.insert(5);
	unorder_set.insert(3);
	unorder_set.insert(4);
	unorder_set.insert(6);
	cout << "unorder_set: " << endl;
	for (auto it : unorder_set)
		cout << it << ' ';
	cout << endl;

	set<int> myset;
	myset.insert(7);
	myset.insert(5);
	myset.insert(3);
	myset.insert(4);
	myset.insert(6);
	cout << "set: " << endl;
	for (auto it : myset)
		cout << it << ' ';
	cout << endl;

	system("pause");
	return 0;
}