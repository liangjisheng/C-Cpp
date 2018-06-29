//定义函数   int gettimeofday ( struct timeval * tv , struct timezone * tz )
//函数说明   gettimeofday()会把目前的时间用tv所指的结构返回，
//当地时区的信息则放到tz所指的结构中。
// timeval:
/* struct timeval {
long tv_sec; //秒
long tv_usec;//微秒
};
timezone 结构定义
struct timezone {
int tz_minuteswest; //和Greenwich 时间差了多少分钟
int tz_dsttime; //日光节约时间的状态
}*/

#include"time.h"
#include"unistd.h"
#include"stdio.h"

int main() {
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	printf("tv_sec:%d\n",tv.tv_sec);
	printf("tv_usec:%d\n",tv.tv_usec);
	printf("tz_minuteswest:%d\n",tz.tz_minuteswest);
	printf("tz_dsttime:%d\n",tz.tz_dsttime);
	return 0;
}
