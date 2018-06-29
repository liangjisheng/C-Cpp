//���庯��   int gettimeofday ( struct timeval * tv , struct timezone * tz )
//����˵��   gettimeofday()���Ŀǰ��ʱ����tv��ָ�Ľṹ���أ�
//����ʱ������Ϣ��ŵ�tz��ָ�Ľṹ�С�
// timeval:
/* struct timeval {
long tv_sec; //��
long tv_usec;//΢��
};
timezone �ṹ����
struct timezone {
int tz_minuteswest; //��Greenwich ʱ����˶��ٷ���
int tz_dsttime; //�չ��Լʱ���״̬
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
