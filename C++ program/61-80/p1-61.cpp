#include<iostream.h>
main()
{
    int i;
    //������������
    union utag  {
          char    c;
          int     k;
          float   x;
    };

    //�������ϱ���
    union utag u; 

    // ʹ�����ϱ����е��ַ��ͳ�Ա 
    u.c='*';
    cout<<"u.c="<<u.c<<endl;

    // ʹ�����ϱ����е����ͳ�Ա 
    u.k=1000;
    cout<<"u.k="<<u.k<<endl;

    // ʹ�����ϱ����еĸ����ͳ�Ա 
    u.x=3.1416;
    cout<<"u.x="<<u.x<<endl;

    //�������ϱ���ʱ��ʼ��
    utag u1={'A'};

    //ͬʱ�������ϱ����ĸ���Ա
    cout<<"u1.c="<<u1.c<<endl;
    cout<<"u1.k="<<u1.k<<endl;
    cout<<"u1.x="<<u1.x<<endl;
}
