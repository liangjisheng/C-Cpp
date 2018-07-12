// 不使用中间变量，交换a,b的值，使用异或
#include"stdio.h"
#include"iostream"

int main()
{
	int a,b;
	printf("请输入a,b:");
	scanf("%d%d",&a,&b);

	// 方案1,缺陷a,b如果是两个较大的数，a=a+b是可能越界
	a=a+b;
	b=a-b;
	a=a-b;
	printf("方案1:交换后:a=%d,b=%d\n",a,b);

	// 方案2，没有越界情况发生
	a=a^b;
	b=a^b;
	a=a^b;
	printf("方案2:交换后:a=%d,b=%d\n",a,b);

	system("pause");
	return 0;
}