//���庯��   time_t time(time_t *t);
//����˵��   �˺����᷵�شӹ�Ԫ1970��1��1�յ�UTCʱ���0ʱ0��0������������������������
//���t ���ǿ�ָ��Ļ����˺���Ҳ�Ὣ����ֵ�浽tָ����ָ���ڴ档

#include"time.h"
#include"stdio.h"

int main() {
	int seconds=time((time_t*)NULL);
	printf("%d\n",seconds);
	return 0;
}