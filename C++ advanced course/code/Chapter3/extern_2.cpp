
// C++֧�����أ���C��֧�����أ��������ԭ��ȫ�ֱ���������C++�������
// ���ſ��е�������C���Բ�ͬ
// �������ڽ��б���ʱ���Ծֲ�������ͨ���ֲ�������ջ�Ͼ�ָ֡��ebp��ƫ����
// �����з��ʵģ��������ĳ�Ա������ͨ��������ڶ����׵�ַ��ƫ����������
// ���ʵģ��������ᷢ����ͻ

#include <iostream>

using std::cout;
using std::endl;

#ifdef __cplusplus
extern "C" {
#endif

int gvar = 5;

void testfunc() { gvar++; }

int main()
{
	cout << gvar << endl;
	testfunc();
	cout << gvar << endl;

	system("pause");
	return 0;
}


#ifdef __cplusplus
}
#endif