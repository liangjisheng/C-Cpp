// system，是一种windows操作系统下的函数语言
// system函数需加头文件<stdlib.h>后方可调用
#include"stdlib.h"
#include"stdio.h"
void main() {
	printf("lishuyu\n");
	// system("color 0A");函数可以改变控制台的前景色和背景，其中0是背景色代号，
	// A是前景色代号。各颜色代码如下：
	// 0=黑色 1=蓝色 2=绿色 3=湖蓝色 4=红色 5=紫色 6=黄色 7=白色 8=灰色 
	// 9=淡蓝色 A=淡绿色 B=淡浅绿色 C=淡红色 D=淡紫色 E=淡黄色 F=亮白色
	char i,j;
	for(i=0;i<16;i++) {
		switch(i) {
		case 10: i='A';break;
		case 11: i='B';break;
		case 12: i='C';break;
		case 13: i='D';break;
		case 14: i='E';break;
		case 15: i='F';break;
		}
		for(j=0;j<16;j++) {
			switch(j) {
			case 10: j='A';break;
			case 11: j='B';break;
			case 12: j='C';break;
			case 13: j='D';break;
			case 14: j='E';break;
			case 15: j='F';break;
			}
			system("color ij");
			printf("change the BackgroundColor and Textcolor\n");
		}
	}

	// 实线冻结屏幕，观察程序运行结果,与getchar()等价
	system("pause"); 
}