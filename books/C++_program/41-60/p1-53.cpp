#include<iostream.h>
main()
{
    //����ṹ����
    struct human {
       char name[10];
       int sex;
       int age;
    };

    //�����ṹ�����ͽṹָ�����,����ʼ��
    struct human x={"WangPing",1,30},*p=NULL;

    //�ṹָ�����ָ�����
    p=&x;

    //��ʾ�ṹ������ֵ
    cout<<"x.name="<<x.name<<endl;
    cout<<"x.sex="<<x.sex<<endl;
    cout<<"x.age="<<x.age<<endl;
  
    //���ýṹָ����ʾ�ṹ�����е�����
    cout<<"(*p).name="<<(*p).name<<endl;
    cout<<"(*p).sex="<<(*p).sex<<endl;
    cout<<"(*p).age="<<(*p).age<<endl;
    cout<<"p->name="<<p->name<<endl;
    cout<<"p->sex="<<p->sex<<endl;
    cout<<"p->age="<<p->age<<endl;

    //ͨ���ṹָ��Ϊ�ṹ������������
    cout<<"name:";
    cin>>(*p).name;
    cout<<"sex:";
    cin>>(*p).sex;
    cout<<"age:";
    cin>>(*p).age;

    //��ʾ�ṹ������ֵ
    cout<<"x.name="<<x.name<<endl;
    cout<<"x.sex="<<x.sex<<endl;
    cout<<"x.age="<<x.age<<endl;
}
