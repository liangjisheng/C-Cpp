#include <iostream.h>
main()
{
    int a,b;
    //��������
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;

    //�����ж�
    if (b!=0 && a%b==0) {
        cout<<b<<" divides "<<a<<endl;
        cout<<"a/b="<<a/b<<endl;
    }
    else
        cout<<b<<" does not divide "<<a<<endl;
}


