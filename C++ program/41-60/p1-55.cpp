#include<iostream.h>
main()
{
    //����ṹ����
    struct human {
       char name[10];
       int sex;
       int age;
    };

    //�����ṹ����ͽṹָ�����,����ʼ��
    human x[]={{"WeiPing",1,30},{"LiHua",1,25},{"LiuMin",0,23}},*p=NULL;

    //���±����������ṹ�����Ԫ��
    for (int i=0;i<3;i++)
    {
        cout<<x[i].name<<'\t';
        cout<<x[i].sex<<'\t';
        cout<<x[i].age<<endl;
    }
    cout<<"----------------"<<endl;

    //�ýṹָ������ṹ�����Ԫ��
    for (p=x;p<=&x[2];p++)
    {
        cout<<p->name<<'\t';
        cout<<p->sex<<'\t';
        cout<<p->age<<endl;
    }
}
