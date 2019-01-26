#include"iostream"
#include"fstream"
#include"string"
using namespace std;
int main(int argc,char *argv[])
{
	static string FILENAME="test.txt";
	char buffer[50],ch;
	int count=0;
	ifstream fin(FILENAME.c_str(),ios_base::binary);
	while(fin.get(ch)){
		buffer[count++]=ch;
	}
	buffer[count]='\0';
	//fin.read(buffer,sizeof(buffer));
	cout<<buffer<<endl;
	/*ofstream fout;
	fout.open(FILENAME.c_str(),ios_base::binary);//以标准字符模式打开
	fout<<"Hello,world!"<<endl;
	fout<<"Hello,world!";
	fout.close();*/
	return 0;
}