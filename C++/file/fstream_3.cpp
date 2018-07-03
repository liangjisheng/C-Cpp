#include"stdafx.h"
#include"tchar.h"
#include"iostream"
#include"iomanip"
#include"fstream"
using namespace std;

int _tmain(int argc,_TCHAR* argv[])
{
	cout<<"li"<<endl;
	cout<<fixed<<1.2345562345666<<endl;
	cout<<fixed<<setprecision(2)<<1.2345677889<<endl;

	int year,month,day;
	ifstream fin("Date.txt");
	if(!fin.bad()) {
		// fin.ignore(256,'\n');	// 忽略的字符数，知道遇到'\n'
		fin>>year>>month>>day;
		cout<<year<<' '<<month<<' '<<day<<endl;
		fin.close();
	}
	else cout<<"无法打开文件进行读取"<<endl;

	cout<<"input new date:";
	cin>>year>>month>>day;
	ofstream fout("Date.txt");
	if(!fout.bad()) {
		// fout.seekp(ios_base::end);
		fout<<year<<' '<<month<<' '<<day<<endl;
		fout.close();
	}
	else cout<<"无法打开文件进行写入"<<endl;

	return 0;
}