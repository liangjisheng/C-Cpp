#include <iostream.h>  //����iostream.hͷ�ļ�
main()
{
    //�������ͱ���
    int a,b; 

    //�Ӽ�����Ϊ���ͱ�����ֵ
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;

    //����������������
    cout<<a<<"+"<<b<<"="<<a+b<<endl;
    cout<<a<<"-"<<b<<"="<<a-b<<endl;
    cout<<a<<"*"<<b<<"="<<a*b<<endl;
    cout<<a<<"/"<<b<<"="<<a/b<<endl;
    cout<<a<<"%"<<b<<"="<<a%b<<endl;

    //�������
    short n=32767,m;    //nȡshort���͵����ֵ
    cout<<"n="<<n<<endl;
    m=n+1;      //�������
    cout<<"n+1="<<m<<endl;
}
