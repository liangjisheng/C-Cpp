// a,b,不能使用"if","?:","switch"或其他判断语句，找出两个数中较大的值
#include "stdio.h"
#include "iostream" // include system()
#include "math.h"

int main()
{
	int a,b;
	printf("输入a,b的值:");
	scanf("%d%d",&a,&b);

	// 方案1
	int max=((a+b)+abs(a-b))/2;
	printf("a,b中较大的值为:%d\n",max);

	// 方案2
	int c=a-b;
	char *strs[2]={"a大","b大"};
	c=unsigned(c)>> (sizeof(int)*8-1);
	printf("%s\n",strs[c]);

	system("pause");
	return 0;
}