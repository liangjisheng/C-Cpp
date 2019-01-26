// system，是一种windows操作系统下的函数语言
// system函数需加头文件<stdlib.h>后方可调用
#include"stdlib.h"
#include"stdio.h"
void main() {
	printf("About to spawn and run a DOS command\n");
	// 查看当前目录下的所有目录与文件
	system("dir");
	getchar();
}