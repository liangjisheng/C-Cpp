#include <iostream>

using namespace std;

class Base{
public:
    Base() {}
    virtual ~Base() {}
};

class Derived : public Base {
public:
    Derived() {}
    virtual ~Derived() {}
};

int main()
{
    Base* b;
    Derived* d = new Derived();
    b = d;  // Don't need a cast to go up the inheritance hierarchy
    d = static_cast<Derived*>(b);   // Need a cast to go down the hierarchy
    Base base;
    Derived derived;
    Base& br = derived;
    Derived& dr = static_cast<Derived&>(br);

    // ��������ת����������ָ������ã����������ڶ�����
    // static_cast����ת����ִ�������ڼ�����ͼ�⡣�������κ�
    // Baseָ��ת��ΪDerivedָ�룬���߽�Base����ת��ΪDerived����
    // ����������ʱBaseʵ���ϲ�����һ��Derived,Ҳ�����
    // ����Ĵ�������������벢ִ�У�����ʹ��ָ��d���ܵ���������
    // �Ľ���������ڴ���д�����˶���ı߽�
    Base* b1 = new Base();
    Derived* d1 = static_cast<Derived*>(b);
    // dynamic_castִ�������ڼ�����ͼ��

    return 0;
}
