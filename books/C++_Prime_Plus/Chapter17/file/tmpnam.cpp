// tmpnam.cpp -- use tmpnam() makes some temporary filenames
// char* tmpnam(char * pszName);
// 可以生成TMP_MAX个不同的文件名，每个文件包含的字符不超过L_tmpnam个
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