#include <iostream>

using namespace std;

//virtual����Ĵ�����Ҫ�ر���һ����Ķ�������һ������Ϊ��ֵ���й���ʱ��
//������ӵ��һ��virtual�����Ӷ�����ô��ʹbitwise copy semanticsʧЧ��
//ÿ������������������������е�virtual�����Ӷ����λ����ִ���ڼ�׼���׵�
//����G++��virtual�����Ӷ����������������ĩ�ˣ�����bitwise copy semantics(��λ����)
//���ܻ��ƻ������λ�ã����Ա��������������Լ��ϳɳ����ĸ��ƹ��캯���������жϡ�

class Base{
public:
    Base() { mBase = 100; }
    virtual ~Base() {}
    virtual void print() {}
private:
    int mBase;
};

class VBase : virtual public Base{
public:
    VBase() { mVBase = 101; }
    virtual ~VBase(){}
    virtual void print() {}
    int mVBase;
};

class Derived : public VBase{
public:
    Derived() { mDerived = 102; }
    virtual ~Derived() {}
    virtual void print() {}
    int mDerived;
};

int main()
{
    // ���һ����Ķ�����������һ������Ϊ��ֵ���й��죬
    // ��ôʹ��bitwise copy semantics���������صĲ�����
    VBase vb1;
    VBase vb2 = vb1;

    // ������Ȼ�Ƿ�������һ��������Ķ�����Ϊ��������ĳ�ֵ���г�ʼ��ʱ��
    // ����������£�Ϊ����ȫ��ȷ�����vb�ĳ�ֵ���趨������������ϳ�һ��
    // ���ƹ��캯��������һЩ���룬����ɸ���������Ķ��������������
    // ���ֳ�Ա�����ĳ�ʼ��������ȷ�趨�Ļ����vptr��ֵ��
    Derived d;
    VBase vb = d;

    int *p = (int*)&d;
    for(size_t i = 0; i < sizeof(d) / sizeof(int); ++i){
        cout << *p << endl;
        ++p;
    }

    p = (int*)&vb;
    cout << endl;
    for(size_t i = 0; i < sizeof(vb) / sizeof(int); ++i){
        cout << *p << endl;
        ++p;
    }

    Base b;
    cout << endl;
    p = (int*)&b;
    for(size_t i = 0; i < sizeof(vb) / sizeof(int); ++i){
        cout << *p << endl;
        ++p;
    }

    return 0;
}
