//定义函数   time_t time(time_t *t);
//函数说明   此函数会返回从公元1970年1月1日的UTC时间从0时0分0秒算起到现在所经过的秒数。
//如果t 并非空指针的话，此函数也会将返回值存到t指针所指的内存。

#include"time.h"
#include"stdio.h"

int main() {
	int seconds=time((time_t*)NULL);
	printf("%d\n",seconds);
	return 0;
}