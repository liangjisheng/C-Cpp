
#include <stdio.h>
#include "windows.h"

int main() {
	// tmpfile:创建临时文件
	FILE *tempfp;
	tempfp=tmpfile();
	if (tempfp)
		printf("Temporary file be created.\n");
	else 
	{
		printf("Unalbe to create temporary file.\n");
		exit(1); 
	}
	Sleep(5000);
	
	return 0;
}