#include"stdio.h"
int main()
{
	char string[50];
	// scanf("%s",string);不能接受空格字符
	/*printf("Input[^\\n] string\n");
	scanf("%[^'\n']",string);
	printf("The s[^\\n]string :%s\n",string);
	fflush(stdin);// 清空缓冲区
	printf("Input [^a] string:\n");
	scanf("%[^a]",string);
	printf("a' ends input :%s\n",string);
	fflush(stdin);*/
	printf("Input [A-F] string\n");
	scanf("%[A-F]",string);
	printf("String is:%s\n",string);

	return 0;
}