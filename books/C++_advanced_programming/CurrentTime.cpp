// C��׼�⣬ֻ�ܾ�ȷ���뼶
#include <stdio.h>
#include <time.h>

int main()
{
	// time(0) ���ص�ֵ�Ǵ�����ڼ�Ԫ��ʼ�����ھ���������
	// windowsϵͳ�ļ�ԪΪ1970��1��1��0ʱ0��0��
	time_t tt = time(0);
	char tmp[64] = {0};
	// ʹ��localtime()ת���ɱ���ʱ��
	strftime(tmp, sizeof(tmp), 
		"%Y/%m/%d\n%X\n%A\n�����%j��\n%z", localtime(&tt));
	puts(tmp);
	
	getchar();
	return 0;
}