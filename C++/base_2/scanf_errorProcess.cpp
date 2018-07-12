
// scanf()的出错处理,scanf()返回成功读取项的个数

#include <stdio.h>

int main()
{
	long n;
	printf("input integers(not less 0):\n");
	int nRet = scanf("%ld", &n);
	while(n >= 0 && 1 == nRet)
	{
		printf("nRet = %d, value = %d\n", nRet, n);
		nRet = scanf("%ld", &n);
	}

	printf("nRet = %d, value = %d\n", nRet, n);

	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	return 0;
}