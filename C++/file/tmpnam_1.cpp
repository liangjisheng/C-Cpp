
#include <stdio.h>
#include "windows.h"

int main() 
{
	// tmpnam:创建临时文件名
	char tmp[10];
	tmpnam(tmp);
	printf("The temporary name is:%s\n",tmp);
	
	return 0;
}