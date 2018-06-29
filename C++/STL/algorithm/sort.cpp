#include"iostream"
#include"vector"
#include"string"
#include"algorithm"
using namespace std;

// void print(int n) { cout<<n<<' '; }
void print(string str) { cout<<str<<' '; }

// template<class RandomAccessIterator>
// void sort(RandomAccessIterator first,RandomAccessIterator last)

int main()
{
	vector<string> vecStr;
	vecStr.push_back("li");
	vecStr.push_back("shu");
	vecStr.push_back("yu");
	vecStr.push_back("liang");
	vecStr.push_back("ji");
	vecStr.push_back("sheng");

	cout<<"Before sort:"<<endl;
	for_each(vecStr.begin(),vecStr.end(),print);
	cout<<endl;

	sort(vecStr.begin(),vecStr.end());
	cout<<"After sort(from small to big):"<<endl;
	for_each(vecStr.begin(),vecStr.end(),print);
	cout<<endl;

	// 将排序完成的容器进行翻转，实现从大到小排序
	reverse(vecStr.begin(),vecStr.end());
	cout<<"After sort(from big to small):"<<endl;
	for_each(vecStr.begin(),vecStr.end(),print);
	cout<<endl;

	system("pause");
	return 0;
}