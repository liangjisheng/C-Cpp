#include <iostream.h>  //����iostream.hͷ�ļ�
#include<iomanip.h>   // iomanip.hͷ�ļ�����setprecision()�Ķ���
main()
{
    //float�ͱ��������������롢��������
    float fx,fy;   
    cout<<"fx=";
    cin>>fx;
    cout<<"fy=";
    cin>>fy;
    cout<<fx<<"+"<<fy<<"="<<fx+fy<<endl;
    cout<<fx<<"-"<<fy<<"="<<fx-fy<<endl;
    cout<<fx<<"*"<<fy<<"="<<fx*fy<<endl;
    cout<<fx<<"/"<<fy<<"="<<fx/fy<<endl<<endl;
    //cout<<fx<<"%"<<fy<<"="<<fx%fy<<endl;  Error!

    //double�ͱ��������������롢��������
    float dx,dy;  
    cout<<"dx=";
    cin>>dx;
    cout<<"dy=";
    cin>>dy;
    cout<<dx<<"+"<<dy<<"="<<dx+dy<<endl;
    cout<<dx<<"-"<<dy<<"="<<dx-dy<<endl;
    cout<<dx<<"*"<<dy<<"="<<dx*dy<<endl;
    cout<<dx<<"/"<<dy<<"="<<dx/dy<<endl<<endl;
    //cout<<fx<<"%"<<fy<<"="<<fx%fy<<endl;  Error!

    //����float��double�������ݵ���Чλ
    fx=10.0;fy=6.0;
    float fz=fx/fy;
    dx=10.0;dy=6.0;
    double dz=dx/dy;
    cout<<"fz=";
    cout<<setprecision(20)<<fx<<"/"<<fy<<"="<<fz<<endl;
    cout<<"dz=";
    cout<<setprecision(20)<<dx<<"/"<<dy<<"="<<dz<<endl<<endl;;

    //float�����
    float x=3.5e14;
    cout<<"x="<<x<<endl;
    cout<<"x*x="<<x*x<<endl;
    cout<<"x*x*x="<<x*x*x<<endl;
}
