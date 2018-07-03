使用ofstream文件输出流对象将一些数据输出到output文本文件中
#include"iostream"
#include"fstream"
using namespace std;
int main()
{
	ofstream fout;
	fout.open("output.txt");//打开一个output文本文件，如果没有则创建
	int num=150;
	char name[]="John Doe";
	if(fout.fail())
		cout<<"Open the file failed."<<endl;
	fout<<"Here is a number: "<<num<<endl;//输入数据到output文本文件中
	fout<<"Now here is a string: "<<name<<endl;//输入数据到output文本文件中
	return 0;
}
