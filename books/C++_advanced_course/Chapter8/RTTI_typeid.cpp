
// RTTI��Runtime Type Identification����д��������ʱ����ʶ�����˼��RTTI
// ������C++���Լ�����������֮һ������C++�����ܵ�Ҫ���йأ���̬����ʶ��
// ����һ���̶����������Ч�ʵĽ��ͣ����Գ���ȷ�б�Ҫ������Ӧ��������RTTI��ʹ��

// typeid���Ǵ������������������Ҳ�������ھ�̬��ȷ����������ʽ������
// typeid���Ծ�̬��ȷ�������������ͣ�Ҳ���Զ�̬��ȷ�������������ͣ���ȡ����
// �����������Ƿ�ӵ���麯��,��typeid�Ĳ�������һ�������������͵ı���������
// ��һ�������麯���Ķ���ʱ��typeid�����������ڱ���׶�ȷ���ģ���һ�־�̬
// �������ж�

#include <iostream>

using namespace std;

template<typename T>
void func(T a)
{
	if(typeid(T) == typeid(int))
		cout << "Instance with int" << endl;
	else if(typeid(T) == typeid(double))
		cout << "Instance with double" << endl;
}

// typeid�����ʱ������������������̬��ȷ��ָ���������ָ����������
// ��ʱҪ��typeid�������Ķ���һ��Ҫӵ���麯��

class A
{
public:
	virtual void func() {}
};

class B : public A{};

void reportA(A *pa)
{
	if(typeid(*pa) == typeid(A))
		cout << "Type of *pa is:A" << endl;
	else if(typeid(*pa) == typeid(B))
		cout << "Type of *pa is:B" << endl;
}

void reportB(B *pb)
{
	if(typeid(*pb) == typeid(A))
		cout << "Type of *pb is:A" << endl;
	else if(typeid(*pb) == typeid(B))
		cout << "Type of *pb is:B" << endl;
}

void func_1()
{
	// �������A��func��virtualȥ������ôtypeid(*pa)�Ľ����Զ��typeid(A)
	// typeid(*pb)�Ľ����Զ��typeid(B),typeidʵ���ϱ����һ�־�̬�����
	A a, *pa;
	B b, *pb;
	pa = &a;
	reportA(pa);
	pa = &b;
	reportA(pa);

	pb = static_cast<B*>(&a);
	reportB(pb);
	pb = &b;
	reportB(pb);
}


int main()
{
	//func(1);
	//func(0.5);

	func_1();

	system("pause");
	return 0;
}

// C++��һ�еĶ�̬���ƣ������麯����RTTI�ȣ�������ͨ��ָ�����������ʵ��
// ���仰˵��ָ����ָ�Ķ�������������󶨵Ķ��������н׶ο���������ָ��
// ������ʱ�����Ͳ�һ�£������ʹ��ָ������ã�����ֱ��ͨ�����������ʶ���
// ��ô��ʹ����ӵ�ж�̬��Ϣ(�麯����)������Ķ�̬��Ϣ�뾲̬��������ʱ����Ϣ
// ��Ȼһ�£���û�б�Ҫ�����麯�������������ӵ���麯������û���麯��
// ���Ŷ�̬��Ϣ��Ҳ���޷�������ʱ��̬�ж�ָ����ָ����(���������󶨶���)
// ��ʵ������
