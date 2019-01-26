// count
#include"iostream"
#include"set"
#include"algorithm"
using namespace std;

int main()
{
	multiset<int,less<int> > intSet;
	intSet.insert(85);
	intSet.insert(90);
	intSet.insert(100);
	intSet.insert(85);
	intSet.insert(85);
	cout<<"Set: ";
	multiset<int,less<int> >::iterator it=intSet.begin();
	for(int i=0;i<intSet.size();i++)
		cout<<*it++<<' ';
	cout<<endl;

	int cnt=count(intSet.begin(),intSet.end(),85);	// 统计85分的数量
	cout<<"85的数量为:"<<cnt<<endl;

	system("pause");
	return 0;
}