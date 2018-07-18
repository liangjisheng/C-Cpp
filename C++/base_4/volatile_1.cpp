
/***********************************************************
 * @name: volatile_1.cpp
 * @brief: test volatile
 * @author: Jisheng Liang
 * @date: 2018/7/10 15:25:32
 * @version: 1.0
 **********************************************************/

//���� volatile ���͵ı�����ϵͳÿ���õ�����ʱ����ֱ�ӴӶ�Ӧ���ڴ浱����ȡ����
//�������� cache ���е�ԭ����ֵ������Ӧ����δ֪��ʱ�ᷢ���ı仯��ϵͳ�����ֱ����Ĵ�
//�������Ż�������ȻҲ����Ϊ������ֵ��ʱ�����ܱ仯�����

#include <stdio.h>

// Debug:10 10, Release:10 10
void test1()
{
	int i = 10;
	int a = i;
	printf("i = %d\n", a);

	// �������������þ��Ǹı��ڴ��� i ��ֵ�������ֲ��ñ�����֪��
	__asm {
		mov dword ptr[ebp - 4], 20h
	}
	int b = i;
	printf("i = %d\n", b);
}

// Debug:10 10, Release:10 32
void test2()
{
	volatile int i = 10;
	int a = i;
	printf("i = %d\n", a);

	// �������������þ��Ǹı��ڴ���i��ֵ�������ֲ��ñ�����֪��
	__asm {
		mov dword ptr[ebp - 4], 20h
	}
	int b = i;
	printf("i = %d\n", b);
}

void main()
{
	printf("no volatile\n");
	test1();
	printf("\nvolatile\n");
	test2();

	getchar();
}
