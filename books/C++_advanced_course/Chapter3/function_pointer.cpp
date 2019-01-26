
// ��һ�ֺ����лص�����(callbakc function).�ص�������һ�������˺�����ԭ��
// ���������ɵ�������ʵ�ֵ�һ�ֶ�̬Ӧ��ģʽ����ʵ�ֵ���ʱ���Ƚ��ص�����
// �ĵ�ַ��Ϊ����֮һ���ݸ����������������������ڲ�ͨ������ָ����ûص�
// �������ص������Ļ��ƴ��������������뱻��������̬�󶨵����ƣ�Ϊ�û��ṩ
// ��һ�ֳ�����ò���ϵͳ���ܵķ����ֶ�

#include <iostream>

using std::cout;
using std::endl;

class DoubleValue
{
public:
	double GetValue() { return 3.7; }
	static int RetInt() { return 5; }
};

typedef int(*pInt)();

double operator+(DoubleValue &d, pInt pfunc)
{
	return d.GetValue() + pfunc();
}


int f() { return 1; }

// ��ʾ��������ָ��
void invoke1(int (*func)()) { cout << (*func)() << endl; }

// ��ʽ��������ָ��
void invoke2(int func()) { cout << func() << endl; }


int main()
{
	DoubleValue obj;
	// ��ΪRetInt�Ǿ�̬�����Կ���ֱ�Ӹ�ֵ����ľ�̬��Աֻ���޶����������
	// �ⲿ��Ա
	pInt p1 = obj.RetInt;
	// endl��ʵ��һ������ģ�壬Ҳ����˵������operator<<����һ������ָ��
	// ��Ϊ���Ĳ���
	cout << obj + p1 << endl;

	invoke1(f);
	invoke2(f);

	system("pause");
	return 0;
}