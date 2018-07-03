//二进制数据块的读取read write
//函数原型  read(char *buf,int num);
//函数原型  write(char *buf,int num);
//成员函数 int gcount();来取得实际读取的字符数
#include"iostream"
#include"fstream"
#include"cstring"
using namespace std;
int main()
{
	char str1[]="heilongjiang";
	int n[5];
	ifstream in;
	ofstream out("yyy.yyy");
	out.write(str1,strlen(str1));
	out.close();
	in.open("yyy.yyy");
	in.read((char*)n,sizeof(n));
	for(int i=0;i<5;i++)
		cout<<n[i]<<" ";
	cout<<endl;
	in.close();
	return 0;
}