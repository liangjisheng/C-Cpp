#include<iostream.h>
main()
{
    //����������ָ�����
    int a,b,c,*ip;

    //ָ�����ipָ�����a
    a=100;
    ip=&a;        //ʹָ����� ip ָ�����a
    cout<<"a="<<a<<endl;
    cout<<"*ip="<<*ip<<endl;
    cout<<"ip="<<ip<<endl;

    //ָ�����ipָ�����b
    ip=&b;        //ʹָ����� ip ָ�����b
    b=200;
    cout<<"b="<<b<<endl;
    cout<<"*ip="<<*ip<<endl;
    cout<<"ip="<<ip<<endl;

    //ָ�����ipָ�����c
    ip=&c;        //ʹָ����� ip ָ�����b
    *ip=a+b;
    cout<<"c="<<c<<endl;
    cout<<"*ip="<<*ip<<endl;
    cout<<"ip="<<ip<<endl;
}
