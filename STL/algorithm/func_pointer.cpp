#include"iostream"
#include"tchar.h"
using namespace std;

// 定义pPrintFunc为指向函数的类型
typedef void (*pPrintFunc)(int);

void PrintMessage(int nScore,pPrintFunc pFunc) {
	cout<<"=================="<<endl;
	// (*pFunc)为回调函数，通过改变(*pFunc)的行为来改变PrintMessage()的行为
	(*pFunc)(nScore);
	cout<<"++++++++++++++++++"<<endl;
}

void PrintFailed(int n) { cout<<"socre="<<n<<" failed"<<endl; }
void PrintPass(int n) { cout<<"score="<<n<<" pass"<<endl; }
void PrintExcellent(int n) { cout<<"score="<<n<<" excellent"<<endl; }

int _tmain(int argc,_TCHAR* argv[])
{
	pPrintFunc pFunc; // 定义函数指针类型变量
	int nScore=44;
	if(nScore<60) pFunc=PrintFailed;
	else if(nScore>=60 && nScore<100) pFunc=PrintPass;
	else pFunc=PrintExcellent;
	PrintMessage(nScore,pFunc);

	system("pause");
	return 0;
}