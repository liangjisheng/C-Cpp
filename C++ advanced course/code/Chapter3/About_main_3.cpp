
#include <iostream>

using std::endl;
using std::cout;

// ���е��ⲿ����Ĺ��캯����������main()����ִ�еģ����Ҫ�����еľ�̬��Ա
// ������г�ʼ������ô��Щ����Ĺ��캯��Ҳ����main()����֮ǰִ�еģ������Щ
// ���캯���л����������������Ļ����Ϳ���ʹ����ĺ�������main()ִ��

class A
{
public:
	A() { cout << "In constructor" << endl; }
};

A a;

int main()
{
	cout << "In main()" << endl;

	system("pause");
	return 0;
};