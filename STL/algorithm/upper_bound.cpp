#include"iostream"
#include"vector"
#include"algorithm"
using namespace std;

void print(int n) { cout<<n<<' '; }
bool ispass(int n) { return n>=60; }

int main() 
{
	vector<int> vec;
	vec.push_back(45);
	vec.push_back(55);
	vec.push_back(60);
	vec.push_back(60);
	vec.push_back(66);
	vec.push_back(75);
	vec.push_back(85);

	sort(vec.begin(),vec.end());
	// 获取容器中大于及格分数的临界点
	// upper_bound()算法返回指向这个临界点的迭代器
	vector<int>::iterator itpass=upper_bound(
		vec.begin(),vec.end(),59);
	// 定义可以保存两个迭代器的pair对象
	pair<vector<int>::iterator,vector<int>::iterator> passRange;
	// 获取容器中等于某个值的数据范围 equal_range()算法返回一个pair对象
	// first成员为起始位置，second成员为结束位置
	passRange=equal_range(vec.begin(),vec.end(),60);

	cout<<"所有及格的分数是:"<<endl;
	for_each(itpass,vec.end(),print);
	cout<<endl;
	cout<<"所有及格的学生人数为:"<<int(vec.end()-itpass)<<endl;
	cout<<"刚好及格的学生人数为:"
		<<int(passRange.second-passRange.first)<<endl;

	// 可以用count()和count_if()实现统计功能
	int nAllpass=count_if(vec.begin(),vec.end(),ispass);
	cout<<"所有及格的学生人数为:"<<nAllpass<<endl;
	// 统计刚好及格的人数
	int nPass=count(vec.begin(),vec.end(),60);
	cout<<"刚好及格的人数为:"<<nPass<<endl;

	system("pause");
	return 0;
}