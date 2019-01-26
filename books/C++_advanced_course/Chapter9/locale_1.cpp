
// ��Ч��locale������"C",���κ�Ԥ�����locale."C"��ʾû��Ӣ���ASCII
// ��locale,���ڷǹ��ʻ�������ʹ�õ�Ĭ�Ϸ�ʽ.�ÿ��ַ�����ʾ��locale����""
// ���ʾϵͳѡ��ı���ϰ��,���뵱ǰ�������й�

#include <iostream>
#include <locale>

using namespace std;

// �Ϸ���������ϵͳԴ�ļ���getqloc.c�ж����

int main()
{
	locale native("");		// ����locale
	locale usa("American_USA.1252");		// ����
	locale Holland("Dutch");
	locale global;			// ȫ��locale
	cout << "native: " << native.name() << endl;
	cout << "classic: " << locale::classic().name() << endl;	// ��ǰȫ��locale
	cout << "global: " << global.name() << endl;
	cout << "Holland: " << Holland.name() << endl;
	cout << "usa: " << usa.name() << endl;

	system("pause");
	return 0;
}