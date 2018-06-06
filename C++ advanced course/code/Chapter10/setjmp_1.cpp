
// C���Դ����쳣ͨ����3�ֵ��͵ķ���
// 1:������Ϣ��ͨ�������ķ���ֵ��ã������������ֵ�����ã��������
// һȫ�ִ����жϱ�־(��׼C������errno()��perrno()����֧����һ����)
// 2:��ʹ��C��׼����һ�㲻̫���õ��źŴ���ϵͳ������signal()����(�ж�
// �¼���������)��raise()����(�����¼�),�����źŲ������ʹ����������
// �Ͱ�װ���ʵ��źŴ���ϵͳ������ʹ���������������г�����ʱӦ���ܽ��
// ���źŲ����⣬���ڴ�����Ŀ���ԣ���ͬ��֮����źſ��ܻ������ͻ
// 3:ʹ��C��׼���еķǾֲ���ת����:setjmp()��longjmp().setjmp()��������
// �����д洢һ���͵�����״̬,�������������longjmp()�ɻָ�setjmp()
// �������趨״̬���Ӷ�ʵ��goto����޷�ʵ�ֵ�"����ת".���ȱ��洢�ĵص�
// �ڻָ�ʱ�����Ե�֪�Ǵ�������ת�����ģ�Ҳ����˵����ȷ���������ĵص�

#include <iostream>
#include <setjmp.h>

using namespace std;

class gname
{
public:
	gname() { cout << "gname" << endl; }
	~gname() { cout << "~gname" << endl; }
};

jmp_buf g_jmp;

void test()
{
	gname name;
	for(int i = 0; i < 3; i++)
		cout << "There is no interesting gname." << endl;
	longjmp(g_jmp, __LINE__);
}

int main()
{
	// setjmp(jmp_buf);�ѵ�ǰ����״̬�����������Ϣ�����jmp_buf���͵ı���
	// �У�������0������������Ϊ��ͨ���ĺ���.Ȼ�����ʹ��ͬһ��jmp_buf����
	// longjmp(),�������ͻ�ص�setjmp()ִ�еĵط������ҽ�longjmp()�ĵڶ���
	// ������Ϊ����setjmp()�ķ���ֵ.����������ж��jmp_buf�Ϳ��Ե��������
	// �����ͬλ�õ���Ϣ
	if(setjmp(g_jmp) == 0)
	{
		cout << "one,two,three..." << endl;
		test();
	}
	else
		cout << "It's fantastic!" << endl;

	system("pause");
	return 0;
}