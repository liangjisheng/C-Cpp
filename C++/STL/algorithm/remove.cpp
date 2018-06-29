#include"iostream"
#include"vector"
#include"algorithm"
using namespace std;

bool isfail(int nScore) { return nScore<60; }
void print(int nScore) { cout<<nScore<<' '; }

int main()
{
	vector<int> vecScore;
	vecScore.push_back(82);
	vecScore.push_back(72);
	vecScore.push_back(-1);
	vecScore.push_back(-1);
	vecScore.push_back(32);
	vecScore.push_back(45);
	cout<<"原始数据:"<<endl;
	for_each(vecScore.begin(),vecScore.end(),print);
	cout<<endl;
	// 删除容器中所有值为-1的数据
	// 使用新的迭代器来保存容器的结束位置
	vector<int>::iterator itend=
		remove(vecScore.begin(),vecScore.end(),-1);
	cout<<"删除-1之后的数据:"<<endl;
	for_each(vecScore.begin(),itend,print);
	cout<<endl;
	// 使用60替代所有不及格的成绩
	replace_if(vecScore.begin(),itend,isfail,60);
	cout<<"最终数据:"<<endl;
	for_each(vecScore.begin(),itend,print);
	cout<<endl;

	system("pause");
	return 0;
}