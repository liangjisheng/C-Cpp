
#include <stdio.h>
#include <time.h>
// ȫ��ִ�е�ʱ�����ε�ʵ�ʶ�Ϊ0��ֻ���ڵ��Ե�ʱ���ִ��for
// ѭ������Ķ���,����������ݿ��Կ�����ʹ�üĴ�������ʱ������
// ʱ���ʹ����ͨ������ʱ��Ҫ�죬��������ÿ�ζ��죬��Ϊregister
// ֻ�ǰ�ʾ���������˱�����Ϊһ���Ĵ���������������ÿ�ζ�����
// ��Ϊ�Ĵ���������
// ����register����ʹ�õ���Ӳ��CPU�еļĴ������Ĵ��������޵�ַ��
// ���Բ���ʹ��ȡ��ַ�����"&"��Ĵ��������ĵ�ַ��

// register ˵����
// (1)ֻ�оֲ��Զ���������ʽ����������Ϊ�Ĵ�����������������ȫ�ֱ��������С�
// (2)һ�������ϵͳ�еļĴ�����Ŀ�����޵ģ����ܶ����������Ĵ���������
// (3)�ֲ���̬�������ܶ���Ϊ�Ĵ���������
// (4)��������Ѿ���ʱ����Ϊ���ڵļ���������ٶȹ��죬���Ժ���ʹ��

int main()
{
	clock_t start, end;
	int test = 0;
	start = clock();
	register int temp, i;
	for(i = 0; i <= 500; i++)
		for(temp = 0; temp <= 100; temp++)
		{
			test = i + temp;
			// printf("%d\n", i + temp);
		}
	end = clock();
	printf("register val time %d\n", end - start);

	int k1, k2;
	start = clock();
	for(k1 = 0; k1 <= 500; k1++)
		for(k2 = 0; k2 <= 100; k2++)
		{
			test = k1 + k2;
			// printf("%d\n", k1 + k2);
		}
	end = clock();
	printf("normal val time %d\n", end - start);

	getchar();
	return 0;
}