
// clock_t clock()�õ�����CPUʱ�䣬��ȷ��1 / CLOCKS_PER_SEC��
// clock()���ش��������������̵������е���clock()����ʱ֮���
// CPUʱ�Ӽ�ʱ��Ԫ
// CLOCKS_PER_SEC������ʾһ���ӻ��ж��ٸ�ʱ�Ӽ�ʱ��Ԫ

#include <stdio.h>
#include <time.h>
#include <math.h>

int main()
{
	printf("1������%d��ʱ�Ӽ�ʱ��Ԫ\n", CLOCKS_PER_SEC);
	
	long i = 10000000L;
	clock_t start = 0, finish = 0;
	long lTime = 0;
	printf("��%ld��ѭ����Ҫ��ʱ��Ϊ: ", i);
	start = clock();
	while (i--)
		double x = sin(0.001) + cos(4556.443);
	finish = clock();
	lTime = finish - start;
	printf("%ld����\n", lTime);

	getchar();
	return 0;
}