
// ���󲢲���ͻȻ���������ģ������������ͬʱ��������Ͱ��������еĶ���
// C++���������µĴ���˳��:
// (1)���ĳ������л��ִ࣬�л����Ĭ�Ϲ��캯����������ctor-initializer
// �е����˻���Ĺ��캯������ʱ����������캯����������Ĭ�Ϲ��캯��
// (2)��ķǾ�̬���ݳ�Ա����������˳�򴴽�
// (3)ִ�и���Ĺ��캯����
// ���Եݹ�ʹ����Щ����

#include <iostream>

using namespace std;

class Something{
public:
    Something() { cout << "2"; }
};

class Parent{
public:
    Parent() { cout << "1"; }
};

class Child : public Parent {
public:
    Child() { cout << "3"; }
private:
    Something mDataMember;
};

int main()
{
    Child myChild;          // print 123

    return 0;
}
