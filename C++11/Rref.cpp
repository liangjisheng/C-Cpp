// ��ֵͨ����һЩ��ֵ��������ʱ�������������ı�����
// ���纯���ķ���ֵ����ֵ���þ��������Щ��ֵ�����ã�
// C++��ͨ�������&&������һ����ֵ���ã���ԭ�ȵ�&��
// Ϊ��ֵ����
#include"stdio.h"

int CreateInt(int nInt)
{ return nInt; }

int main()
{
	int n=0;
	int& Lref=n;
	printf("Lref n=%d\n",Lref);
	int&& Rref=CreateInt(1);
	printf("Rref n=%d\n",Rref);

	getchar();
	return 0;
}
