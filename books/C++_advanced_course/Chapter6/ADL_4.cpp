
// 2、在某个类的成员函数中，如果被调用的函数不是在本类中定义的，那么他就是一个
// 外部函数。这时，编译器会根据顺序查找规则，从类所在的作用域向外一直到全局
// 作用域查找重载函数，知道确定重载函数的集合时停止查找。这时除了OL规则发生作用
// 外，KL规则也起作用

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
				// 被调用函数KoenigLookupMethod在类KoenigLookup中没有定义
				// 必须到类域之外去查找，此时找到的三个重载函数集合中包含
				// 三个候选函数，无法从中挑选最合适的版本，因此编译器报错
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

