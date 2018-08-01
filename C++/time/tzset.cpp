//函数原型:void tzset(void)
//函数功能:UNIX兼容函数，用于得到时区，在DOS环境下无用途

#include"time.h"
#include"stdlib.h"
#include"stdio.h"

int main() {
	time_t td;
	putenv("TZ=PST8PDT");
	tzset();
	time(&td);
	printf("Current time=%s",asctime(localtime(&td)));

	return 0;
}