
// �������cpp�ļ��ж�������ͬ��ȫ�ֱ���(����)���ͻᷢ���ض������
// �������������Ϊȫ�־�̬����(����)���Ϳ��Ա����ض������
// ���˿���ʹ��static�ؼ��ֱ���ȫ�ֱ���(����)���ض������֮�⣬
// ������ͨ���������ֿռ�ķ�ʽʵ��
// ��һ��Դ�ļ��У����Զ������������ֿռ䣬�ڸ�����ͬһԴ�ļ��е�
// ����������ֿռ�����ݻᱻ�ϲ���һ���γ�һ��ͳһ���������ֿռ�

#include <iostream>

using namespace std;

static int gvar = 4;

void show2() { cout << gvar << endl; }


namespace
{
	int gvar1 = 5;
	extern double dvar;
}


void show4()
{
	cout << gvar1 << endl;
	cout << dvar << endl;
}

namespace { double dvar = 7.6; }



int main()
{
	void show1();			// ������������show1()������������Ҳ���
	show1();
	show2();
	cout << "\n\n";

	void show3();
	show3();
	show4();

	system("pause");
	return 0;
}

