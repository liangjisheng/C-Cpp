#include"iostream"
#include"fstream"
using namespace std;
int main()
{
	ofstream fout;
	fout.open("a.txt");
	char ch[]="liangjisheng";
	int i;
	for(i=0;i<sizeof(ch);i++)
		fout<<ch[i];
	fout.close();
	char s;
	ifstream fin;
	fin.open("a.txt");
	while(!fin.eof()){
	fin.get(s);
	cout<<s;}
	cout<<endl;
	return 0;
}