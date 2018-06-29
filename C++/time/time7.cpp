#include"stdio.h"
#include"stdlib.h"
#include"time.h"
#include"dos.h"
char *tzstr="TZ=PST8PDT";

int main() {
	time_t t;
	struct tm *gmt,*area;
	putenv(tzstr);
	tzset();
	t=time(NULL);
	area=localtime(&t);
	printf("Local time is:%s",asctime(area));
	gmt=gmtime(&t);
	printf("GMT is:%s",asctime(gmt));

	return 0;
}