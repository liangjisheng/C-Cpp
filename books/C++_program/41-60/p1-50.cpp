#include<iostream.h>
main()
{
    //����ָ������
    char *colors[]={"Red","Blue","Yellow","Green"}; 
    //ָ��ָ���ָ�����
    char **pt;             

    //ͨ��ָ��ָ��ı���������ָ�������
    pt=colors;
    for (int i=0;i<=3;i++) {
        cout<<"pt="<<pt<<endl;
        cout<<"*pt="<<*pt<<endl;
        cout<<"**pt="<<**pt<<endl;
        pt++;
    }
}
