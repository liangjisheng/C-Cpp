
// time_t time(time_t *timer);

#include <stdio.h>
#include <time.h>

int main()
{
	// time_t������time.h�У�time_t��long
	time_t rawtime;
	struct tm timeinfo;
	// time()��ȡ��ǰʱ���1970��1��1��0ʱ0��0�������
	time(&rawtime);
	// ת��Ϊ����ʱ�䣬tmʱ��ṹ
	localtime_s(&timeinfo, &rawtime);
	char szTime[64] = {0};
	// ת��Ϊ��׼ASCIIʱ���ʽ ���� �� �� ʱ���֣��� ��
	asctime_s(szTime, &timeinfo);
	printf("The current date/time is: %s\n", szTime);

	// tm_year since 1900
	printf("timeinfo.year: %d\n", timeinfo.tm_year);
	printf("timeinfo.tm_mon: %d\n", timeinfo.tm_mon);
	printf("timeinfo.tm_mday: %d\n", timeinfo.tm_mday);
	printf("timeinfo.tm_hour: %d\n", timeinfo.tm_hour);
	printf("timeinfo.tm_min: %d\n", timeinfo.tm_min);
	printf("timeinfo.tm_sec: %d\n", timeinfo.tm_sec);
	// tm_wday������������ܵĵڼ���
	printf("timeinfo.tm_wday: %d\n", timeinfo.tm_wday);
	// tm_mday�������������µĵڼ���
	printf("timeinfo.tm_mday: %d\n", timeinfo.tm_mday);
	// tm_day��������ǽ���ĵڼ���
	printf("timeinfo.tm_yday: %d\n", timeinfo.tm_yday);

	getchar();
	return 0;
}