#include"iostream"
#include"tchar.h"
#include"locale.h"
#include"wchar.h"
using namespace std;

int _tmain(int argc,_TCHAR* argv[])
{
	// ����wcout����Ҫ����locale��Ϊ�������Բ����������
	wcout.imbue(locale("chs"));

	const char* psa="A����ABC";
	cout<<psa; cout.clear(); cout<<endl;

	const wchar_t* psw=L"W����ABC";
	wcout<<psw; wcout.clear(); wcout<<endl;

	wstring s(L"�Ұ���");
	// wcout<<s<<endl;
	wcout<<L"�Ұ���"<<endl;

	// C
	printf("\nC:\n");
	// cout<<"12345678\n";
	printf("\t%s\n",psa);
	printf("\t%ls\n",psw);

	system("pause");
	return 0;
}