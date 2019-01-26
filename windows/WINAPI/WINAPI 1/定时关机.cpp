// C 调用DOS命令实现定时关机
#include"stdio.h"
#include"string.h"
#include"stdlib.h"

void print() {
	printf("︳﹃﹄︻Ⅲ＄αβγδεóǎíōūúǔěňǚ零贰拾太〧\n");
	printf("mv?e??かすぬひスツニカクбеаёОНспн├──卍\n");
	printf("C 调用DOS命令实现定时关机\n");
	printf("1:实现10分钟内关机.\n");
	printf("2:立即关机.\n");
	printf("3:注销系统.\n");
	printf("0:退出.\n");
}

int main() {
	system("title C语言关机程序");// 设置cmd窗口标题
	system("mode con cols=120 lines=25");	// 窗口宽度高度
	system("color 0B");
	system("date /T");
	char cmd[20]="shutdown -s -t ";
	char t[5]="0";
	print();
	int c;
	scanf("%d",&c);
	getchar();
	switch(c) {
	case 1:printf("您想在多少秒后自动关机?(0-600)\n");
		scanf("%s",t); 
		system(strcat(cmd,t));break;
	case 2:system("shutdown -p"); break;
	case 3:system("shutdown -1"); break;
	case 0:break;
	default:printf("Error!\n");
	}
	system("pause");
	return 0;
}
