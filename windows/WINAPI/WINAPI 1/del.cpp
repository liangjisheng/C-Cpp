// 删除文件
#include"stdlib.h"
#include"stdio.h"
// 以下一段代码不能很好的工作
/*int main() {
	char filepath[100];
	printf("Input the file absolute path:");
	scanf("%s",&filepath);
	printf("%s\n",filepath);
	if(system("del filepath"))
		printf("file have deleted.\n");
	system("pause");
	return 0;
}*/

// this can work well
int main() {
	//if(system("del d:\\123.txt"))
	//	printf("文件以成功删除\n");
	system("del d:\\123.txt");
	system("pause");
	return 0;
}