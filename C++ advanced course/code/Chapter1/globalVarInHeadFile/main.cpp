
#include "test.h"			// mian.cpp�ļ���û�ж����TEST_CPP,�൱�ڶ�myVar����������
// Ӧ������Ԥ����test.cpp,����������У��˱��뵥Ԫ������TEST_CPP�꣬���ԾͶ���
// ��myVar���������Ȼ����Ԥ����main.cpp��ʱ�򣬲�û�ж���TEST_CPP�꣬���������
// ���뵥Ԫ�У����൱�ڶ�myVar����������

int main()
{
	Print();			// 0
	myVar = 1;
	Print();			// 1

	return 0;
}