#include"iostream"
#include"fstream"
using namespace std;
int main()
{
	int n[5]={1,2,3,4,5};
	register int i;
	ofstream out("test.txt",ios::out|ios::binary);
	if(!out)
	{cout<<"Cannot open file.n"<<endl;return 1;}
	out.write((char*)&n,sizeof(n));//二进制文件写函数
	out.close();
	for(i=0;i<5;i++)
		n[i]=0;
	ifstream in("test.txt",ios::in|ios::binary);
	if(!in)
	{cout<<"Cannot open file.n"<<endl;return 1;}
	in.read((char*)&n,sizeof(n));//二进制文件读函数
	for(i=0;i<5;i++)
		cout<<n[i]<<" ";
	cout<<endl;
	in.close();
	return 0;
}