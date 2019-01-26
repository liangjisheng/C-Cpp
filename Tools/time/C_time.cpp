
// time_t time(time_t *timer);

#include <stdio.h>
#include <time.h>

int main()
{
	// time_t定义与time.h中，time_t是long
	time_t rawtime;
	struct tm timeinfo;
	// time()获取当前时间距1970年1月1日0时0分0秒的秒数
	time(&rawtime);
	// 转换为当地时间，tm时间结构
	localtime_s(&timeinfo, &rawtime);
	char szTime[64] = {0};
	// 转换为标准ASCII时间格式 星期 月 日 时：分：秒 年
	asctime_s(szTime, &timeinfo);
	printf("The current date/time is: %s\n", szTime);

	// tm_year since 1900
	printf("timeinfo.year: %d\n", timeinfo.tm_year);
	printf("timeinfo.tm_mon: %d\n", timeinfo.tm_mon);
	printf("timeinfo.tm_mday: %d\n", timeinfo.tm_mday);
	printf("timeinfo.tm_hour: %d\n", timeinfo.tm_hour);
	printf("timeinfo.tm_min: %d\n", timeinfo.tm_min);
	printf("timeinfo.tm_sec: %d\n", timeinfo.tm_sec);
	// tm_wday代表今天是这周的第几天
	printf("timeinfo.tm_wday: %d\n", timeinfo.tm_wday);
	// tm_mday代表今天是这个月的第几天
	printf("timeinfo.tm_mday: %d\n", timeinfo.tm_mday);
	// tm_day代表今天是今年的第几天
	printf("timeinfo.tm_yday: %d\n", timeinfo.tm_yday);

	getchar();
	return 0;
}