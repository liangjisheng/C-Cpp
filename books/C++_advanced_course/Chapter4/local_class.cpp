
// �ֲ���ĳ�Ա���������붨���������ڣ��ֲ����в��ܶ��徲̬���ݳ�Ա����Ҫ
// ���������ݳ�Ա�ĳ�ʼ�������޷����

#include <iostream>

using std::cout;
using std::endl;

void func()
{
	static int s;
	class A
	{
	public:
		int num;
		void init(int i) { s = i; }
	};
	A a;
	a.init(8);
	cout << s << endl;
}


int main()
{
	func();

	system("pause");
	return 0;
}

