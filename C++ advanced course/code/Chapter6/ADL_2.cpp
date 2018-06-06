
// C++����Ĳ��ҹ������Ordinal Lookup(OL,˳����ҹ���)

#include <iostream>

using namespace std;

void func() { cout << "function in global namespace" << endl; }

namespace NS1
{
	void func() { cout << "function in namespace1" << endl; }

	namespace NS2
	{
		// void func(char *s) { cout << s << endl; }

		class KoenigLookup
		{
		public:
			// func()����˳��Ϊ��KoenigLookup,���ֿռ�NS1::NS2,���ֿռ�NS1,
			// �����ȫ����,�����ֿռ�NS1::NS2�ҵ���func()���Ͳ����ȸ���Χ��
			// �������в��ң�����ʱû���ҵ����ʵ����غ����汾�����Ա������
			void koeniglookup() { func(); }
		};
	}
}

int main()
{
	NS1::NS2::KoenigLookup k1;
	k1.koeniglookup();

	system("pause");
	return 0;
}
