// tmpnam.cpp -- use tmpnam() makes some temporary filenames
// char* tmpnam(char * pszName);
// ��������TMP_MAX����ͬ���ļ�����ÿ���ļ��������ַ�������L_tmpnam��
#include"cstdio"
#include"iostream"

int main()
{
	using namespace std;
	cout<<"This system can generate up to "<<TMP_MAX
		<<" temporary names of up to "<<L_tmpnam
		<<" character.\n";
	char pszName[L_tmpnam]={'\0'};
	cout<<"Here are the name:\n";
	for(int i=0;i<10;i++) {
		tmpnam(pszName);
		cout<<pszName<<endl;
	}

	system("pause");
	return 0;
}