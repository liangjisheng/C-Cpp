
// 2����ĳ����ĳ�Ա�����У���������õĺ��������ڱ����ж���ģ���ô������һ��
// �ⲿ��������ʱ�������������˳����ҹ��򣬴������ڵ�����������һֱ��ȫ��
// ������������غ�����֪��ȷ�����غ����ļ���ʱֹͣ���ҡ���ʱ����OL����������
// �⣬KL����Ҳ������

#include <iostream>

using namespace std;

namespace KLSpace2 { class KLArg2; }		// ����

namespace KLSpace1
{
	class KLArg1 {};

	void KoenigLookupMethod(KLSpace1::KLArg1&, KLSpace2::KLArg2&)
	{ cout << "Namespace KLSpace1::KoenigLookupMethod" << endl; }
}

namespace KLSpace2
{
	class KLArg2 {};

	void KoenigLookupMethod(KLSpace1::KLArg1&, KLSpace2::KLArg2&)
	{ cout << "Namespace KLSpace2::KoenigLookupMethod" << endl; }
}

void KoenigLookupMethod(KLSpace1::KLArg1&, KLSpace2::KLArg2&)
{ cout << "Global KoenigLookupMethod" << endl; }

namespace KL
{
	void KoenigLookupMethod(KLSpace1::KLArg1&, KLSpace2::KLArg2&)
	{ cout << "Namespace KL::KoenigLookupMethod" << endl; }

	namespace KL_Inside
	{
		void KoenigLookupMethod(KLSpace1::KLArg1&, KLSpace2::KLArg2&)
		{ cout << "Namespace KL::KL_Inside::KoenigLookupMethod" << endl; }

		class KoenigLookup
		{
		public:
			void koenigLookup()
			{
				KLSpace1::KLArg1 klArg1;
				KLSpace2::KLArg2 klArg2;
				// �����ú���KoenigLookupMethod����KoenigLookup��û�ж���
				// ���뵽����֮��ȥ���ң���ʱ�ҵ����������غ��������а���
				// ������ѡ�������޷�������ѡ����ʵİ汾����˱���������
				KoenigLookupMethod(klArg1, klArg2);
			}
		private:
			/*void KoenigLookupMethod(KLSpace1::KLArg1&, KLSpace2::KLArg2&)
			{
				cout << "Non-Static Member KL::KL_Inside::KoenigLookup::";
				cout << "KoenigLookupMethod" << endl;
			}*/

			/*static void KoenigLookupMethod(KLSpace1::KLArg1&, KLSpace2::KLArg2&)
			{
			cout << "Static Member KL::KL_Inside::KoenigLookup::";
			cout << "KoenigLookupMethod" << endl;
			}*/
		};
	}
}


int main()
{
	KL::KL_Inside::KoenigLookup k1;
	k1.koenigLookup();

	system("pause");
	return 0;
}

