#include <iostream.h>
main()
{
    double  r=1.0;
    cout<<"r="<<r<<endl;
    double l;
    l=2*3.1416*r;           //����Բ���ܳ�����ֵ������l
    cout<<"l="<<l<<endl;    //��ʾԲ���ܳ�	
    double s=3.1416*r*r;     //����Բ���������ֵ������s 
    cout<<"s="<<s<<endl;    //��ʾԲ�����

    cout<<"R=";            //��ʾ��ʾ�������Ϣ
    cin>>r;                 //��������
    l=2*3.1416*r;           //����Բ���ܳ�����ֵ������l
    cout<<"l="<<l<<endl;    //��ʾԲ���ܳ�
    s=3.1416*r*r; 
    cout<<"s="<<s<<endl;    //��ʾԲ�����
}
