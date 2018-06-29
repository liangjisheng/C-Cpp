#include"iostream"
#include"vector"
#include"functional"
#include"algorithm"
using namespace std;

// bind1st和bind2nd函数用于将一个二元算子(binary functor,bf)
// 转换成一元算子(unary functor,uf)为了达到这个目的,
// 它们需要两个参数：要转换的bf和一个值v
void print(int& a)
{ cout<<a<<' '; }

int main()
{
	int a[]={1,2,3,4,5,6,100,200,123,456,134};
	vector<int> arr(a,a+sizeof(a)/sizeof(int));
	cout<<"原向量元素:"<<endl;
	for_each(arr.begin(),arr.end(),print);
	cout<<endl;

	// 这里比较表达式相当于arr.value<100,移除所有小于100的元素
	/*cout<<"删除所有小于100的元素"<<endl;
	arr.erase(remove_if(arr.begin(),arr.end(),
		bind2nd(less<int>(),100)),arr.end());
	for_each(arr.begin(),arr.end(),print);
	cout<<endl;*/

	// 这里比较表达式相当于100<arr.value,移除所有大于100的元素
	/*cout<<"删除所有大于100的元素"<<endl;
	arr.erase(remove_if(arr.begin(),arr.end(),
		bind1st(less<int>(),100)),arr.end());
	for_each(arr.begin(),arr.end(),print);
	cout<<endl;*/

	// 移除所有小于等于100的元素
	cout<<"删除所有小于等于100的元素"<<endl;
	arr.erase(remove_if(arr.begin(),arr.end(),
		not1(bind2nd(greater<int>(),100))),arr.end());
	for_each(arr.begin(),arr.end(),print);
	cout<<endl;

	system("pause");
	return 0;
}