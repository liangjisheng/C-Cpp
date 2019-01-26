#include"iostream"
#include"vector"
#include"algorithm"
using namespace std;

// template<class BidirectionalIterator1,class BidirectionalIterator2>
// BidirectionalIterator2 copy_backward(BidirectionalIterator1 first,
//		BidirectionalIterator1 last,BidirectionalIterator2 result);
void print(int n) { cout<<n<<' '; }

int main()
{
	vector<int> vec,vec1;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	cout<<"原始数据:"<<endl;
	for_each(vec.begin(),vec.end(),print);
	cout<<endl;

	vec.resize(vec.size()*2);
	copy_backward(vec.begin(),vec.begin()+vec.size()/2,
		vec.end());
	cout<<"扩大后的数据:"<<endl;
	for_each(vec.begin(),vec.end(),print);
	cout<<endl;

	vec1.resize(vec.size()/2);
	copy_backward(vec.begin(),vec.begin()+vec.size()/2,
		vec1.end());
	cout<<"vec1:"<<endl;
	for_each(vec1.begin(),vec1.end(),print);
	cout<<endl;

	system("pause");
	return 0;
}