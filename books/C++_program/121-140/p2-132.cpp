#include<iostream.h>
//�����������麯���Ļ���
class Base {
public:
    //���������麯��
    virtual void aFn1(void){    
        cout<<"aFnl is in Base class."<<endl;
    }
    virtual void aFn2(void) {    
        cout<<"aFn2 is in Base class."<<endl;
    }
    //������麯��
    void aFn3(void) {    
        cout<<"aFn3 is in Base class."<<endl;
    }
};

//������Derived_1�����¶����˻����е��麯��aFn1
class Derived_1:public Base
{
public:
    void aFn1(void) {   //����aFn1()����
        cout<<"aFnl is in First derived class."<<endl;
    }
    // void aFn3(void) {   �﷨����
    //    cout<<"aFn3 is in First derived class."<<endl;
    //}
};

//������Derived_2�����¶����˻����е��麯��aFn2
class Derived_2:public Base{
public:
    void aFn2(void){   //����aFn2()����
        cout<<"aFn2 is in Second derived class."<<endl;
    }
    // void aFn3(void) {   �﷨����
    //    cout<<"aFn3 is in Second derived class."<<endl;
    //}
};
//main()�����Ķ���
main(void)
{
    //������ʹ�û���Base�Ķ���
    Base b;
    cout<<"Base:"<<endl;
    b.aFn1();
    b.aFn2();
    b.aFn3();
    cout<<"----------------------"<<endl;

    //������ʹ��������Derived_1�Ķ���
    Derived_1 d1;
    cout<<"Derived_1:"<<endl;
    d1.aFn1();
    d1.aFn2();
    d1.aFn3();
    cout<<"----------------------"<<endl;

    //������ʹ��������Derived_2�Ķ���
    Derived_2 d2;
    cout<<"Derived_2:"<<endl;
    d2.aFn1();
    d2.aFn2();
    d2.aFn3();
}
