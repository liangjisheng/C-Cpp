
// ��intel+windows�Ļ����ϣ�����ջ�ķ��������µģ�ջ��ָ����ڴ��ַ����
// ջ��ָ�룬�����Ƚ�ջ�������Ǵ�����ڴ�ĸߵ�ַ��
// ��VC�Ⱦ������C�������У�Ĭ������£�������ջ��˳���Ǵ�������ģ����
// ������ջ�Ժ����һ���̶������ĵ�ַλ�ڵ�һ���ɱ����֮�£�����������
// �洢��

#include <iostream>
// C������Ϊ��ͳһ�ڲ�ͬ��Ӳ��ƽ̨�ϵ�ʵ�֣����Ӵ���Ŀ���ֲ�ԣ��ṩ��
// һϵ�еĺ�������Ӳ��������ͬ�����Ĳ���
#include <stdarg.h>

using std::cout;
using std::endl;

void PrintAll(int n1, ...)
{
	int *ptr = &n1;
	while(*ptr)
	{
		cout << *ptr << " ";
		ptr++;
	}
	cout << endl;

	ptr = &n1;
	while(*ptr)
		cout << *ptr++ << " ";
	cout << endl;

	ptr = &n1;
	while(*ptr++)
		cout << *ptr << " ";
	cout << endl;
}


int SqSum1(int n1, ...)
{
	va_list arg_ptr;
	int nSqSum = 0, n = n1;
	va_start(arg_ptr, n1);
	while(n > 0)
	{
		nSqSum += (n * n);
		n = va_arg(arg_ptr, int);
	}
	va_end(arg_ptr);
	return nSqSum;
}


int SqSum2(int n1, ...)
{
	va_list arg_ptr;
	int nSqSum = 0, n;
	va_start(arg_ptr, n1);
	while(n1 > 0)
	{
		n = va_arg(arg_ptr, int);
		nSqSum += (n * n);
		n1--;
	}
	va_end(arg_ptr);
	return nSqSum;
}


int main()
{
	// PrintAll(3, 4, 5);

	int nSqSum = SqSum1(1, 1, 1, 1);
	cout << nSqSum << endl;
	nSqSum = SqSum1(1, 1, 1, 1, 0);
	cout << nSqSum << endl;
	nSqSum = SqSum2(4, 1, 1, 1, 1);
	cout << nSqSum << endl;

	system("pause");
	return 0;
}