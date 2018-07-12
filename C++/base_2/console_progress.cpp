
// 在控制台下显示进度条
#include <stdio.h>
#include <Windows.h>

int main()
{
	const int NUM = 50;		// 任务完成总量

	for (int i = 0; i <= NUM; ++i)
	{
		// 用Sleep()来代替一些费事的操作，如读写文件，大量的运算
		Sleep(200);		// some work to do
		// 输出百分比,\r是使得光标回到本行的开始处
		printf("%.2lf%%\r", i * 100.0 / NUM);
	}

	printf("\nok\n");

	getchar();
	return 0;
}

// 在控制台显示进度无疑是非常方便的，在很多场合完全可以代替窗口进度条的
// 来美化程序和减小用户等待时的乏味感