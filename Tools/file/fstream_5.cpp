使用ifstream出入流对象输入数据，从input.txt文件中读数据到变量中，输出到屏幕上并检测.
#include"iostream"
#include"fstream"
using namespace std;
int main()
{
	ifstream file;
	file.open("input.txt");
	int n1;
	float real;
	char letter,word[8];
	char buf[100];
	file>>n1>>word>>real>>letter;
	file.getline(buf,99);
	cout<<n1<<endl
		<<word<<endl
		<<real<<endl
		<<letter<<endl
    	<<buf<<endl;
	return 0;
}