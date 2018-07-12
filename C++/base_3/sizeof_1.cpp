#include"iostream"
#include"stdio.h"
#include"string.h"
using namespace std;

struct{
	short a1;
	short a2;
	short a3;
}A;
struct{
	long a1;
	short a2;
}B;

int main()
{
	char* ss1="0123456789";
	char ss2[]="0123456789";
	char ss3[100]="0123456789";
	int ss4[100];
	char q1[]="abc";
	char q2[]="a\n";
	char* q3="a\n";
	char* str1=(char *)malloc(100);
	void* str2=malloc(100);		// malloc()返回void * 类型
	// void * str2=(void *)malloc(100);

	cout<<sizeof(ss1)<<" ";		// 4个字节
	cout<<sizeof(ss2)<<" ";		// 11
	cout<<sizeof(ss3)<<" ";		// 100
	cout<<sizeof(ss4)<<" ";		// 400
	cout<<sizeof(q1)<<" ";		// 4
	cout<<sizeof(q2)<<" ";		// 3
	cout<<sizeof(q3)<<" ";		// 4
	cout<<sizeof(A)<<" ";		// 6
	cout<<sizeof(B)<<" ";		// 8
	cout<<sizeof(str1)<<" ";	// 4
	cout<<sizeof(str2)<<" ";	// 4
	cout<<endl;

	system("pause");
	return 0;
}