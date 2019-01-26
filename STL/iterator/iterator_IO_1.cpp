#include"iostream"
#include"string"
#include"iterator"
#include"fstream"
#include"algorithm"
#include"vector"
using namespace std;

int main()
{
	string from,to;
	cout<<"输入源文件名和目标文件名:\n";
	cin>>from>>to;

	ifstream is(from.c_str());		// 文件输入流
	istream_iterator<string> ii(is);	// 流的输入迭代器
	istream_iterator<string> eos;		// 输入的哨兵

	vector<string> b(ii,eos);	// 用输入初始化b
	sort(b.begin(),b.end());	// 对缓冲区排序

	ofstream os(to.c_str());
	ostream_iterator<string> oo(os,"\n");	// 输出流迭代器

	// 从缓冲区复制到输出，并去掉重复的值
	unique_copy(b.begin(),b.end(),oo);

	return !is.eof() || !os ;
}