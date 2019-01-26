
// 应该说，OL是名字查找的主要规则，只有当引入名称空间、模板机制之后，在OL应用的
// 某些阶段中KL才起作用，并将其作用附加在OL之上，下面分几种情况讨论顺序查找规则和
// Koenig查找规则相组合的结果

// 1、类的成员函数与类外的自由函数同名，类域比名字空间域(包括全局域)有更高的优先
// 级，KL规则的作用范围是名字空间域里的自由函数，当OL应用于类域的成员函数的时候，KL
// 是不起作用的，当进行名字查找的时候，成员函数绝对不会跟非成员函数一起进行重载决议

#include <iostream>

using namespace std;

namespace KLSpace2 { class KLArg2; }		// 声明

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
				// 调用的是类中的成员函数，在类域中找到符合名字的成员函数就停止了
				// 查找，经过重载决议后得到了调用的版本，整个过程中KL规则并没有起
				// 作用，在类域中KL规则是不起作用的
				KoenigLookupMethod(klArg1, klArg2);
			}
		private:
			/*void KoenigLookupMethod(KLSpace1::KLArg1&, KLSpace2::KLArg2&)
			{
				cout << "Non-Static Member KL::KL_Inside::KoenigLookup::";
				cout << "KoenigLookupMethod" << endl;
			}*/

			static void KoenigLookupMethod(KLSpace1::KLArg1&, KLSpace2::KLArg2&)
			{
				cout << "Static Member KL::KL_Inside::KoenigLookup::";
				cout << "KoenigLookupMethod" << endl;
			}
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

