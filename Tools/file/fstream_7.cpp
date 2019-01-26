#include"iostream"
#include"string"//C++字符串类
#include"fstream"//文件流类
#include"iomanip"//I/O格式控制
using namespace std;
int main()
{
	int num=150;
	string str="liangjisheng";
	double x=12.12;
	ofstream fout;//文件输出流对象
	fout.open("output.txt");//打开output.txt文件，若没有此文件，则自动新建一个
	fout<<str<<endl
		<<hex<<num<<endl;//以十六进制将num输入到文件中
	fout<<x<<endl;//将x输入到文件中
	fout.close();

	ifstream fin;//文件输入流对象
	fin.open("output.txt");
	char ch[90];
	fin.getline(ch,20);//读取文件的整行
	cout<<ch<<endl;
	fin.close();

	/*string str2;
	int num2;
	double y;
	ifstream fin;
	fin.open("output.txt");
	fin>>str2>>num2>>y;
	cout<<str2<<endl
		<<num2<<endl
		<<y<<endl;
	fin.close();*/
	return 0;
}