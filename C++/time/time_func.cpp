#include"stdio.h"
#include"stdlib.h"
#include"time.h"
#include"string.h"
#include"dos.h"

/*int main() {
	// char* asctime(const struct tm *tbolck)
	// ��������ָ����tm�ṹ�������(�ֶ�����)ת����
	// ���и�ʽ���ַ���: Mon Nov 21 11:31:54 1983\n\0
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
	// clock �����������ʱ�䣬ȷ��������ʱ��
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
	// char*��ctime(const time_t *time)
	// ��time��ָ�������ʱ��ת��Ϊ�ַ�����ʽ�ı���ʱ�䡣
	// ���ȼ��ں�������asctime(localtime(timer))��
	// �ַ����ĸ�ʽΪ��DDD MMM dd hh:mm:ss YYYY
	time_t t;
	time(&t); // ��ȡϵͳʱ��
	printf("Today's date and time:%s\n",ctime(&t));
	return 0;
}*/

// double difftime(time_t time2,time_t time1)
// ������������ʱ��time1��time2��ʱ������
// ����time1Ϊָ���ĵ�һ��ʱ�䣬time2Ϊָ����
// �ڶ���ʱ�䡣time1ҪС�ڻ����time2��
// ����ֵ������ʱ������Ϊ��λ��double���͡�

/*int main() {
	// struct tm *gmtime(const time_t *timer)
	// �����ں�ʱ��ת��Ϊ�������α�׼ʱ��(GMT)��
	time_t t;
	struct tm *gmt;
	t=time(NULL); // ��ȡϵͳʱ��
	gmt=gmtime(&t);
	printf("GMT is:%s",asctime(gmt));
	return 0;
}*/

/*int main() {
	// struct tm* localtime(const time_t *timer)
	// ��timer��ָ������ʱ��ת��Ϊ�Ա���ʱ���ʾ�ķֶ�ʱ��
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
	// ��tm���͵Ľṹָ��timeptrָ��Ľṹ���е�������ʱ��
	// ת��Ϊtime_t���͵����ں�ʱ�䣬������
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