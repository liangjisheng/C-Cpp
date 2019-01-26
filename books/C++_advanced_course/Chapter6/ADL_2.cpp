
// C++最初的查找规则就是Ordinal Lookup(OL,顺序查找规则)

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
			// func()查找顺序为类KoenigLookup,名字空间NS1::NS2,名字空间NS1,
			// 最后是全局域,在名字空间NS1::NS2找到了func()，就不会先更外围的
			// 作用域中查找，但此时没有找到合适的重载函数版本，所以编译出错
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
