// 将两个实型转换为字符串并连接
#include"stdafx.h"
#include"iostream"
#include"cstdlib"
#include"cstring"
using namespace std;

void CatString(double dbNum1,double dbNum2)
{
	char szNum1[50]={0};
	char szNum2[50]={0};
	_gcvt(dbNum1,10,szNum1);	// 转换
	_gcvt(dbNum2,10,szNum2);
	strcat(szNum1,szNum2);
	cout<<"result:"<<szNum1<<endl;
}

int main()
{
	double d1,d2;
	cout<<"input tow double:";
	cin>>d1>>d2;
	CatString(d1,d2);

	system("pause");
	return 0;
}