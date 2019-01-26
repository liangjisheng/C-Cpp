// 统计单词出现的次数
#include"iostream"
#include"string"
#include"map"
#include"fstream"
#include"algorithm"
#include"ctime"
using namespace std;

map<string,int> m;
void print(const pair<string,int>& r)
{ cout<<r.first<<' '<<r.second<<endl; }

void record(const string& s)
{ m[s]++; }		// m[s]返回所对应的int的值

int main()
{
	double beginTime=clock();

	fstream in("source.txt");
	istream_iterator<string> ii(in);
	istream_iterator<string> eos;

	for_each(ii,eos,record);
	for_each(m.begin(),m.end(),print);
	cout<<endl;

	double endTime=clock();
	cout<<"time:"<<endTime-beginTime<<" ms"<<endl;

	system("pause");
	return 0;
}