// C标准库，只能精确到秒级
#include <stdio.h>
#include <time.h>

int main()
{
	// time(0) 返回的值是从相对于纪元开始到现在经过的秒数
	// windows系统的纪元为1970年1月1号0时0分0秒
	time_t tt = time(0);
	char tmp[64] = {0};
	// 使用localtime()转换成本地时间
	strftime(tmp, sizeof(tmp), 
		"%Y/%m/%d\n%X\n%A\n本年第%j天\n%z", localtime(&tt));
	puts(tmp);
	
	getchar();
	return 0;
}