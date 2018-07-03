#include"iostream"
#include"fstream"
using namespace std;
int main()
{
	ofstream fout;
	fout.open("a.txt");//以读写方式打开，若没有则自动创建一个
	char ch[]="liangjisheng";
	int i;
	for(i=0;i<sizeof(ch);i++)
		fout.put(ch[i]);//输出一个字符到文件中
	fout.close();
	char s;
	ifstream fin;
	fin.open("a.txt");
	while(!fin.eof()){
	fin.get(s);//输入一个字符到s中
	cout<<s;}
	cout<<endl;
	fin.close();

	ifstream ffin;
	ffin.open("a.txt");
	char buf[20];
	ffin.get(buf,9);//输入a.txt文件中的前8个字符到buf中
	cout<<buf<<endl;
	ffin.close();
	return 0;
}