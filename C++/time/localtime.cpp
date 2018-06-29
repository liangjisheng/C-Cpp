//���庯��   struct tm* gmtime(const time_t*timep);
/* define tm
struct tm {
int tm_sec;		//����Ŀǰ������������ΧΪ0-59����������61��
int tm_min;		//����Ŀǰ��������Χ0-59
int tm_hour;	//����ҹ�����ʱ������ΧΪ0-23
int tm_mday;	//Ŀǰ�·ݵ���������Χ01-31
int tm_mon;		//����Ŀǰ�·ݣ���һ�����𣬷�Χ��0-11
int tm_year;	//��1900 ���������������
int tm_wday;	//һ���ڵ�������������һ���𣬷�ΧΪ0-6
int tm_yday;	//�ӽ���1��1�������������������ΧΪ0-365
int tm_isdst;	//�չ��Լʱ������
};
*/

#include"time.h"
#include"stdio.h"

int main() {
	char *wday[]={ "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	time_t timep;
	struct tm *p;
	time(&timep);
	p=localtime(&timep);//ȡ�õ���ʱ��
	printf("%d %d %d\n",(1900+p->tm_yday),(1+p->tm_mon),p->tm_mday);
	printf("%s %d:%d:%d\n",wday[p->tm_wday],p->tm_hour,p->tm_min,p->tm_sec);

	return 0;
}