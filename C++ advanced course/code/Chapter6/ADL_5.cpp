
// ��Ҫע����ǣ��������ص����ֿռ�����ʱ�����һ���������ڽ���KL����ʱ
// ͬ�����������鷳

#include <iostream>

using namespace std;

namespace NS2 { class Derived; }		// ����

namespace NS1
{
	class Base{};

	void func(NS2::Derived &obj) { cout << "in namespace1" << endl; }
}

namespace NS2
{
	class Derived : public NS1::Base {};

	void func(Derived& obj) { cout << "in namespace2" << endl; }
}


int main()
{
	NS2::Derived obj;
	// ��ʵ����ص����ֿռ�����������һ����NS2,һ����NS1�����������涼�ж��庯��func
	// ���±������޷��γ���Ч�����ؾ���
	func(obj);

	system("pause");
	return 0;
}
