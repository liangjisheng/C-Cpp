#include"iostream"
#include"tchar.h"
#include"locale.h"
#include"wchar.h"
using namespace std;

int _tmain(int argc,_TCHAR* argv[])
{
	// 对于wcout，需要将其locale设为本地语言才能输出中文
	wcout.imbue(locale("chs"));

	const char* psa="A汉字ABC";
	cout<<psa; cout.clear(); cout<<endl;

	const wchar_t* psw=L"W汉字ABC";
	wcout<<psw; wcout.clear(); wcout<<endl;

	wstring s(L"我爱你");
	// wcout<<s<<endl;
	wcout<<L"我爱你"<<endl;

	// C
	printf("\nC:\n");
	// cout<<"12345678\n";
	printf("\t%s\n",psa);
	printf("\t%ls\n",psw);

	system("pause");
	return 0;
}