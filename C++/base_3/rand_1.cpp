
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	printf("%d\n", RAND_MAX);
	// 初始化随机数种子
	// time函数返回从1970年1月1日零时零分零秒到目前为止所经过的时间，单位为秒
	srand((int)time(NULL));
	int j = 0;
	for (int i = 0; i < 10; ++i)
	{
		j = rand() * 10 / RAND_MAX + 1;		// 生成1-10之间的随机数
		printf("j = %d\n", j);
	}

	for (int i = 0; i < 10; ++i)
		printf("%d ", rand());
	printf("\n");

	// 生成15550~16549之间的随机数
	unsigned start = (rand() * 1000) / RAND_MAX + 15550;
	printf("start = %d\n", start);
	// 把start变为偶数，如果是奇数，则start变为start - 1的偶数
	start &= ~1;
	printf("start = %d\n", start);

	system("pause");
	return 0;
}