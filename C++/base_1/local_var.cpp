#include"iostream"
#include"tchar.h"
using namespace std;

int* GetLocalVal() {
	int nLocalVal=1;
	return &nLocalVal;
}

int _tmain(int argc,_TCHAR* argv[])
{
	int* pLocalVal=GetLocalVal();
	cout<<"当前局部变量的值为:"<<*pLocalVal<<endl;
	int a;	// 改变内存内容
	cout<<"当前局部变量的值为:"<<*pLocalVal<<endl;

	system("pause");
	return 0;
}