#include"stdafx.h"
#include"memory"	// ����share_ptr
#include"iostream"
#include"tchar.h"
using namespace std;

int _tmain(int argc,_TCHAR* argv[])
{
	shared_ptr<int> pFirst(new int);
	// ��ʱ��ֻ��pFirst���ָ��ָ�����int���͵��ڴ�
	// ������ʱ�����ü�����1
	cout<<"��ǰ���ü�����:"<<pFirst.use_count()<<endl;
	{
		// ��������һ��share_ptr,����pFirst������и�ֵ��
		// ������ָ��ͬһ���ڴ���Դ
		shared_ptr<int> pCopy=pFirst;
		// ����ָ��ͬʱָ��һ���ڴ���Դ��������һ��Դ�����ü�������Ϊ2
		cout<<"��ǰ���ü���:"<<pFirst.use_count()<<endl;
	}
	// ����pCopy�Ŀɼ���pCopy�������������ڣ����ü�����1
	cout<<"��ǰ���ü���:"<<pFirst.use_count()<<endl;

	system("pause");
	// ���������ս���ִ�з��أ�pFirstָ��Ҳ�������������ں�
	// û���κ�ָ��ָ���ڴ���Դ�����ü���Ϊ0���ڴ���Դ�Զ��ͷ�
	cout<<"��ǰ���ü���:"<<pFirst.use_count()<<endl;
	return 0;
}
