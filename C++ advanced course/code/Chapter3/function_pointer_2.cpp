
#include <stdio.h>


class A
{
	char c;
	int i;
	double d;
public:
	A () { c = '0'; i = 1; d = 2.3; }
};


A ReturnObject()
{
	A a;
	return a;
}

int ReturnInt () 
{
	printf("in ReturnInt\n");
	return 1; 
}

typedef void(*Ptr)();


int main()
{
	Ptr p;
	p = reinterpret_cast<Ptr>(ReturnObject);
	// ����ReturnObject���ص���һ������ϴ�Ķ���������������Ϊ�������
	// �������ջ�ϴ���һ����ʱ����(���߾����Ż�֮������һ���Ѿ����ڵĶ���
	// ���ܷ���ֵ)����p������ĺ������䷵��ֵ������void�������������main()
	// ��ͨ��pʵ�ֺ�������ʱ����û��Ϊ��������׼�����ܷ���ֵ�Ŀռ䣬��
	// ReturnObject�ڣ���ִ�е�return a;ʱ�ᷢ�������Ǵ��󣬷���ֵ���Ƿ�
	// ��д�뵽��������ռ�ݵĿռ䣬ʹ�������д���δ֪״̬��
	//p();
	p = reinterpret_cast<Ptr>(ReturnInt);

	// �������ָ��ʵ�ֵĺ��������ǰ�ȫ�ģ�����ֵ��д��Ĵ���eax�У������
	// ��������main()�в�ʹ��eax��ֵ���Ժ��������в�������κ�Ӱ��
	p();

	getchar();
	return 0;
}