
// �������볣����

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

class A
{
    int num;
public:
    A() { num = 5; }
    // ֻ����ķǾ�̬��Ա�������Ա�����Ϊ��������
    // �������͵ĺ���(���ⲿ����)���ܱ�����Ϊ������
    // ����disp�����������أ��������ջᱻ������������
    // void disp(A*), void disp(const A*)
    void disp();
    void disp() const;
    void set(int n) { num = n; }
};

void A::disp() const
{
    cout << num << endl;
}

void A::disp()
{
    cout << "Another version of disp()" << endl;
}


int main()
{
    A a1;
    a1.set(3);
    // ����Ѱ�ҷ�const�汾�����û���ҵ����ڵ��õ�����const�汾
    a1.disp();              // not const

    A const a2;
    a2.disp();             // const

    // ����a1�����const�汾��disp(),����a1����ĳ����û��߳�ָ��
    ((const A&)a1).disp();
    // or
    ((const A*)&a1)->disp();

    system("pause");
    return 0;
}
