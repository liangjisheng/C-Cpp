
// ��ͷ�ļ�handle.h�У��û�ֻ���ھ����handle�Ķ����п���һ��ָ������������
// ��wrapped�����ָ�룬��wrapped�����ȫ��ʵ��ϸ����handle.cpp�У�û���κ�һ��
// ͷ�ļ��ṩ�κ�wrapped����κ���Ϣ�����ھ����Ҫ���Ĺ��������ǿ��Թ̶�������
// ����handle.h���Բ������仯����wrapped���ʵ�ַ����仯ʱ��ֻ��Ҫ���±���
// handle.cpp�����κ�ʹ�õ�handle��(Ҳ���ǰ�����ͷ�ļ�handle.h)��Դ�ļ�������Ҫ
// ���±���

#include "handle.h"
#include <iostream>

using std::cout;
using std::endl;


int main()
{
	handle u;
	cout << u.read() << endl;
	u.destory();
	u.create();
	u.change(9);
	cout << u.read() << endl;

	system("pause");
	return 0;
}

