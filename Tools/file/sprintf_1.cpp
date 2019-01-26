
#include <stdio.h>

int main() 
{
	// sprintf:向字符串写入格式化数据函数
	#define M_PI 3.1415926
	char str[80];
	sprintf(str,"An approximation of Pi is:%f\n",M_PI);
	puts(str);
	return 0;
}