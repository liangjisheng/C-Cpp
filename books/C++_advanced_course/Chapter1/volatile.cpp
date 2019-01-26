
#include <iostream>

using std::cout;
using std::endl;


void test()
{
	int i = 10;
	int a = i;

	cout << a << endl;
	_asm{
		mov dword ptr[ebp - 4], 80
	}
	// ������Ĭ�ϰ�i��ֵ����Ĵ����У�ÿ�η���iֻ��ӼĴ����л�ü���
	// ����Ļ������Ѿ��޸���i��ֵ����ֻ���޸��˼Ĵ����е�ֵ
	// ��û���޸������е�ֵ�����Է�ӳ����b�ϣ�b��Ϊ10
	// ���i��һ�������������ı����������Ż������Ĵ��������������
	int b = i;
	cout << b << endl;
}


void test_1()
{
	// ʹ��volatile�����Ʊ��������Ż�
	volatile int i = 10;
	int a = i;

	cout << a << endl;
	_asm{
		mov dword ptr[ebp - 4], 80
	}

	// Debugģʽ��bΪ10��Releaseģʽ��bΪ80��Ҫע������
	// ��η���i��ʱ����ֱ�Ӵ������з��ʵģ������ǴӼĴ����з��ʵ�
	int b = i;
	cout << b << endl;
}


void test_2()
{
	// �����Ż����ܻὫһЩ"����"�Ĵ��볹��ȥ�������ȷʵ����ִ���ļ��б����ⲿ��
	// ����Ļ���Ҳ���Խ����еı�������Ϊvolatile
	int i, j, k;
	int s;
	// ��Release��ʱ�����������ѭ����ֱ���Ż�Ϊһ����ֵ���s = 5;
	// ��������Ż������Խ�s����Ϊvolatile
	for(i = 0; i < 5; i++)
		for(j = 0; j < 5; j++)
			for(k = 0; k < 5; k++)
				s = 5;
	cout << s << endl;
}


int main()
{
	test();
	test_1();
	test_2();

	system("pause");
	return 0;
}