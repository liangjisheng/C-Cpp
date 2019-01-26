#include"iostream"
#include"vector"
#include"algorithm"
using namespace std;

// template<class InputIterator1,class InputIterator2,class OutputIterator>
// OutputIterator merge(InputIterator1 first1,InputIterator1 last1,
//		InputIterator2 first2,InputIterator2 last2,OutputIterator result);
void print(int n) { cout<<n<<' '; }

int main()
{
	vector<int> vec,vec1;
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(1);
	vec.push_back(9);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(6);

	vec1.push_back(8);
	vec1.push_back(6);
	vec1.push_back(4);
	vec1.push_back(2);
	vec1.push_back(0);
	vec1.push_back(7);
	vec1.push_back(5);
	vec1.push_back(3);

	cout<<"vec before sort:";
	for_each(vec.begin(),vec.end(),print);
	cout<<endl;
	cout<<"vec1 before sort:";
	for_each(vec1.begin(),vec1.end(),print);
	cout<<endl;

	// merge()合并没有排序的两个容器
	vector<int> v1;
	v1.resize(vec.size()+vec1.size());
	merge(vec.begin(),vec.end(),vec1.begin(),vec1.end(),v1.begin());
	cout<<"merge vec and vec1:"<<endl;
	for_each(v1.begin(),v1.end(),print);
	cout<<endl;

	sort(vec.begin(),vec.end());
	sort(vec1.begin(),vec1.end());

	cout<<"vec after sort:";
	for_each(vec.begin(),vec.end(),print);
	cout<<endl;
	cout<<"vec1 after sort:";
	for_each(vec1.begin(),vec1.end(),print);
	cout<<endl;

	// merge()合并两个排好序的容器
	vector<int> v;
	v.resize(vec.size()+vec1.size());
	merge(vec.begin(),vec.end(),vec1.begin(),vec1.end(),v.begin());
	cout<<"merge vec and vec1:"<<endl;
	for_each(v.begin(),v.end(),print);
	cout<<endl;

	// 若两个容器中有相同的元素，merge()并不能去除相同的元素
	// set_union(),合并数据时，如果两个容器中有相同数据，则只合并一份到目标容器
	vector<int> v2;
	v2.resize(vec.size()+vec1.size());
	vector<int>::iterator itend=set_union(vec.begin(),vec.end(),
		vec1.begin(),vec1.end(),v2.begin());
	cout<<"相同数据只复制一份:"<<endl;
	for_each(v2.begin(),v2.end(),print);
	cout<<endl;

	// 返回第一次找到0的迭代器位置
	vector<int>::iterator itfind=find(v2.begin()+1,v2.end(),0);
	v2.resize(itfind-v2.begin());
	cout<<"删除多余的空间v2:"<<endl;
	for_each(v2.begin(),itfind,print);
	cout<<endl;
	cout<<v2.size()<<endl;

	// vector<int>::iterator itend2=remove(v2.begin()+1,v2.end(),0);
	// cout<<"v2:"<<endl;
	// for_each(v2.begin(),itend2,print);
	// cout<<endl;
	// cout<<v2.size()<<endl;

	// 删除容器中所有值为0的数据,新的迭代器保存容器的位置
	// vector<int>::iterator itend2=remove(v2.end()-5,v2.end(),0);
	// cout<<"v2:"<<endl;
	// for_each(v2.begin(),itend2,print);
	// cout<<endl;

	system("pause");
	return 0;
}