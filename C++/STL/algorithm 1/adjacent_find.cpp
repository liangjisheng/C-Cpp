// adjacent.find.cpp 利用adjacent_find 对集合中的元素操作
// 用于返回指定邻近相等的第一个指定的指针，
// 获取指定范围内相等元素的第一个元素的iterator指针
#include"iostream"
#include"set"
#include"algorithm"
using namespace std;

int main()
{
	multiset<int,less<int> > intSet;
	intSet.insert(7);
	intSet.insert(5);
	intSet.insert(1);
	intSet.insert(5);
	intSet.insert(7);
	cout<<"Set:"<<' ';
	multiset<int,less<int> >::iterator it =intSet.begin();
	for(int i=0;i<intSet.size();i++)
		cout<<*it++<<' ';
	cout<<endl;
	cout<<"第一次匹配: ";
	it=adjacent_find(intSet.begin(),intSet.end());
	cout<<*it++<<' ';
	cout<<*it<<endl;

	cout<<"第二次匹配: ";
	it=adjacent_find(intSet.begin(),intSet.end());
	cout<<*it++<<' ';
	cout<<*it<<endl;

	cout<<"第三次匹配: ";
	it=adjacent_find(it,intSet.end());
	cout<<*it++<<' ';
	cout<<*it<<endl;

	system("pause");
	return 0;
}