将源文件每行文本前添加一个行号输出到目的文件中
#include"iostream"
#include"fstream"
#include"iomanip"
using namespace std;
int main()
{
	char s1[500];
	int cnt=0;
	ifstream inf("a.cpp");//打开源文件读
	if(!inf.fail()){
		ofstream outf("b.cpp");//创建目的文件写
		while(!inf.eof()){//是否到达文件末尾
			inf.getline(s1,sizeof(s1-1));//读源文件字符串
			//将字符串添加行号输出到目的文件
			outf<<setfill('0')<<setw(4)<<++cnt<<" "<<s1<<endl;
		}
		outf.close();
		inf.close();
	}
	return 0;
}