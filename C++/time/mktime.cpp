//���庯��   time_t mktime(strcut tm * timeptr);
//����˵��   mktime()����������timeptr��ָ��tm�ṹ����ת����
//�ӹ�Ԫ1970��1��1��0ʱ0��0 �����������UTCʱ����������������

//��time()ȡ��ʱ�䣨������������localtime()
//ת����struct tm ������mktine()��struct tmת����ԭ��������

#include"stdio.h"
#include"time.h"

int main() {
	time_t timep;
	struct tm *p;
	time(&timep);
	printf("time():%d\n",timep);
	p=localtime(&timep);
	timep=mktime(p);
	printf("time()->localtime()->mktime():%d\n",timep);

	return 0;
}

