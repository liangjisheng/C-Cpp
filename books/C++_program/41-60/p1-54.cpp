include<iostream.h>
main()
{
    //����ṹ����
    struct human {
       char name[10];
       int sex;
       int age;
       };

    //�����ṹ�����ͽṹָ��,����ʼ��
    struct human x={"WangPing",1,30},*p=&x;
 
    //���ýṹָ����ʾ�ṹ�е�����
    cout<<"(*p).name="<<(*p).name<<endl;
    cout<<"(*p).sex="<<(*p).sex<<endl;
    cout<<"(*p).age="<<(*p).age<<endl;
    cout<<"-------------------------"<<endl;

    //����new�����Ϊp�����ڴ�
    p=new human;

    //�Ӽ�����Ϊpָ��Ľṹ����ֵ
    cout<<"p->name=";
    cin>>p->name;
    cout<<"p->sex=";
    cin>>p->sex;
    cout<<"p->age=";
    cin>>p->age;
    cout<<"-------------------------"<<endl;

    //��ʾp��ָ�ṹ�����ֵ
    cout<<"p->name="<<p->name<<endl;
    cout<<"p->sex="<<p->sex<<endl;
    cout<<"p->age="<<p->age<<endl;
    cout<<"-------------------------"<<endl;

    //��ʾ�ṹ������ֵ
    cout<<"x.name="<<x.name<<endl;
    cout<<"x.sex="<<x.sex<<endl;
    cout<<"x.age="<<x.age<<endl;

    //�ͷ�pָ����ڴ�
    delete p;  
}
