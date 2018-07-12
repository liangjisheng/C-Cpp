#include"iostream"
#include"string"
using namespace std;

int main(int argc,char * argv[])
{
	string strArr1[]={"Trend","Micro","Soft"};
	string *pStrArr1=new string[2];
	pStrArr1[0]="US";
	pStrArr1[1]="CN";
	cout<<sizeof(strArr1)<<endl;	// 48
	cout<<sizeof(string)<<endl;		// 16
	for(int i=0;i<sizeof(strArr1)/sizeof(string);i++)
		cout<<strArr1[i];
	cout<<endl;

	// sizeof(pStrArr1)=4; sizeof(string)=16
	for(int j=0;j<sizeof(pStrArr1)*8/sizeof(string);j++)
		cout<<pStrArr1[j];
	cout<<endl;

	system("pause");
	return 0;
}