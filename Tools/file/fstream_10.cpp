#include"iostream.h"
#include"fstream.h"
#include"conio.h"
int main()
{
	ofstream outfile("data.txt");
	for(int i=0;i<10;i++)
		outfile<<i<<" ";
	cout<<"写入成功"<<endl;
	outfile.close();
	cout<<"输出文件内容"<<endl;
	ifstream infile("data.txt");
	int num;
	for(int j=0;j<10;j++){
		infile>>num;
		cout<<num<<" ";
	}
	cout<<endl;
	infile.close();
	return 0;
}