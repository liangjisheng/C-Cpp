#include"stdafx.h"
#include"iostream"
#include"omp.h"
using namespace std;

int main()
{
	// ��pragmaָ��ָ������һ�����Բ��е�forѭ��
	// �������������Щָ���Զ���������
	// ��forѭ��������Ӧ�Ĳ��д���
	#pragma omp parallel for
	for(int i=0;i<10;i++)
		cout<<i<<endl;

	system("pause");
	return 0;
}
