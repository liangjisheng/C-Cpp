#include <iostream>

int main()
{
	typedef int(*FunctionPointer)(int);
	int val = 21;
	FunctionPointer funcP;
	// ��������Ӷ�����ͨ����������ʱ�����
	// ��ΪfuncP��ָ��ĵ�ַ�����Ǻ�����ڵ�ַ
	// ֻ�н�ת���������ֵת���ص���ԭʼ���ͣ�����������ȷʹ��reinterpret_cast��ʽ
	funcP = reinterpret_cast<FunctionPointer>(&val);
	funcP(val);

	system("pause");
	return 0;
}