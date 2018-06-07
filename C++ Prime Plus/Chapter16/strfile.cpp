// strfile.cpp -- read strings from a file
#include"iostream"
#include"fstream"
#include"string"
#include"cstdlib"

int main() 
{
	using namespace std;
	ifstream fin;
	fin.open("a.txt");
	if(fin.is_open()==false) {
		cout<<"Cann't open file.Bye\n";
		exit(EXIT_FAILURE);
	}
	string str;
	int count=0;
	getline(fin,str,':');	// ����:�������룬����ʱ����Ϊһ����ͨ�ַ�
	while(fin) {	// while input is good
		++count;
		cout<<count<<": "<<str<<endl;
		getline(fin,str,':');
	}
	cout<<"Bye!\n";
	fin.close();

	return 0;
}