#include<iostream.h>
main()
{
    //����һ������ָ���Ա�Ľṹ����
    struct test {
       char *str;
       int  *ip;
    } x;

    //ʹ�ýṹ����x�е�����ָ��ip
    x.ip=new int;    //����1����Ԫ
    *(x.ip)=100;
    cout<<"x.ip:"<<x.ip<<'\t'<<*(x.ip)<<endl;
    cout<<"---------------"<<endl;
    delete x.ip;
    x.ip=new int[5];    //����5����Ԫ
    for(int i=0;i<5;i++)
        *(x.ip+i)=100+i;
    cout<<"x.ip:"<<endl;
    for(i=0;i<5;i++)
        cout<<x.ip+i<<'\t'<<(*(x.ip+i))<<endl;
    delete x.ip;
    cout<<"---------------"<<endl;

    //ʹ�ýṹ����x�е��ַ���ָ��str
    x.str=new char('A');    //����1����Ԫ
    cout<<"x.str:"<<(*x.str)<<endl;
    cout<<"---------------"<<endl;
    delete x.str;
    x.str=new char[5];    //��������Ԫ
    *x.str='G';
    *(x.str+1)='o';
    *(x.str+2)='o';
    *(x.str+3)='d';
    *(x.str+4)='\0';
    cout<<"x.str:"<<x.str<<endl;
    delete x.str;
    cout<<"---------------"<<endl;

    //�������ṹ����ʱ��ʼ��
    test y={"Very Good!",NULL};
    cout<<"y.str:"<<y.str<<endl;
    cout<<"y.ip:"<<y.ip<<endl;
}
