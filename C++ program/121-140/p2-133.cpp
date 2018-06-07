#include<iostream.h>
//���������
class Base {
public:
    //�����������麯��
    virtual void aFn1(void)=0;
    virtual void aFn2(void)=0;
};

//������Derived_1�и����˻����еĴ��麯��
class Derived_1:public Base
{
public:
    void aFn1(void) {
        cout<<"aFnl is in First derived class."<<endl;
    }
    void aFn2(void) {
        cout<<"aFn2 is in First derived class."<<endl;
    }
};

//������Derived_2�и����˻����еĴ��麯��
class Derived_2:public Base{
public:
    virtual void aFn1(void){
        cout<<"aFn1 is in Second derived class."<<endl;
    }
    void aFn2(void){
        cout<<"aFn2 is in Second derived class."<<endl;
    }
};

//main()�����в��Գ����༰��������Ķ���
main(void)
{
    //�ó����಻�ܴ�������
    //    Base b;  �﷨����
    //    b.aFn1();
    //    b.aFn2();

    //������ʹ��Derived_1��Ķ���
    Derived_1 d1;
    cout<<"Derived_1 d1:"<<endl;
    d1.aFn1();
    d1.aFn2();
    cout<<"------------------"<<endl;

    //������ʹ��Derived_2��Ķ���
    Derived_2 d2;
    cout<<"Derived_2 d2:"<<endl;
    d2.aFn1();
    d2.aFn2();
}
