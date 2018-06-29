#include"stdio.h"
#include"stdlib.h"
#include"time.h"
#include"string.h"
#include"dos.h"

/*int main() {
	// char* asctime(const struct tm *tbolck)
	// 本函数把指定的tm结构类的日期(分段日期)转换成
	// 下列格式的字符串: Mon Nov 21 11:31:54 1983\n\0
	struct tm t;
	char str[80];
	t.tm_sec=1;
	t.tm_min=30;
	t.tm_hour=9;
	t.tm_mday=22;
	t.tm_mon=11;
	t.tm_year=56;
	t.tm_wday=4;
	t.tm_yday=0;
	t.tm_isdst=0;
	strcpy(str,asctime(&t));
	printf("%s",str);
	return 0;
}*/

/*int main() {
	// clock 计算程序运行时间，确定处理器时间
	clock_t start,end;
	start=clock();
	delay(1000);
	// int *a=(int*)malloc(100000000*sizeof(int));
	// for(int i=0;i<100000000;i++)
	//  	a[i]=i;
	// free(a);
	end=clock();
	printf("The time was:%lf\n",(end-start)/CLK_TCK);
	return 0;
}*/

/*int main() {
	// char*　ctime(const time_t *time)
	// 将time所指向的日历时间转换为字符串形式的本地时间。
	// 它等价于函数调用asctime(localtime(timer))。
	// 字符串的格式为：DDD MMM dd hh:mm:ss YYYY
	time_t t;
	time(&t); // 获取系统时间
	printf("Today's date and time:%s\n",ctime(&t));
	return 0;
}*/

// double difftime(time_t time2,time_t time1)
// 计算两个日历时间time1和time2的时间间隔。
// 其中time1为指定的第一个时间，time2为指定的
// 第二个时间。time1要小于或等于time2。
// 返回值：返回时间差，以秒为单位的double类型。

/*int main() {
	// struct tm *gmtime(const time_t *timer)
	// 把日期和时间转换为格林尼治标准时间(GMT)。
	time_t t;
	struct tm *gmt;
	t=time(NULL); // 获取系统时间
	gmt=gmtime(&t);
	printf("GMT is:%s",asctime(gmt));
	return 0;
}*/

/*int main() {
	// struct tm* localtime(const time_t *timer)
	// 把timer所指的日历时间转换为以本地时间表示的分段时间
	time_t t;
	struct tm *tblock;
	t=time(NULL);
	tblock=localtime(&t);
	printf("Local time is:%s\n",asctime(tblock));
	printf("Today's date and time:%s\n",ctime(&t));
	getchar();
	return 0;
}*/

int main() {
	// time_t mktime(struct tm* timeptr)
	// 将tm类型的结构指针timeptr指向的结构体中的日期与时间
	// 转换为time_t类型的日期和时间，并返回
	char *week_day[8]={"Sun","Mon","Tue","Wed","Fri","Sat","Unknow"};
	struct tm t;
	t.tm_year=99;
	t.tm_mon=1;
	t.tm_mday=1;
	t.tm_hour=0;
	t.tm_min=0;
	t.tm_sec=1;
	t.tm_isdst=-1;
	if(mktime(&t)==-1)
		t.tm_wday=7;
	printf("The day is:%s",week_day[t.tm_wday]);
	getchar();
	return 0;
}