
// һ����ԣ�����ֻ�ܶ�����.c�ļ��У�������������.h�ļ��У�����ʹ��Ƴ���
// ��.h�ļ��ж�����������Ƕ�ʵ�ʶ��ԣ�����������ͷ�ļ���ֻ�Ǳ����

#ifndef TEST_H
#define TEST_H

#ifdef TEST_CPP			// �þ��һ�������Ӧ��cpp�ļ��У���ֻ�ܶ���һ��
int myVar = 0;
#else
extern int myVar;		// �����û���壬�൱����cpp�ļ������ñ���
#endif

extern void Print(void);

#endif