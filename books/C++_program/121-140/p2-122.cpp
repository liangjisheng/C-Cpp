#include<iostream.h>
//����ex��
class ex_class 
{
    int a;
    double b; 
public:
    ex_class(int n=1,double x=1.0):a(n),b(x) {}
    void show_value(char *name) {
        cout<<name<<" :"<<endl;
        cout<<"a="<<a<<endl;
        cout<<"b="<<b<<endl;
    }
};

//����main()����
main()
{
    //����ex_class�Ķ�����ʾ
    ex_class obj1,obj2(100,3.5);    
    obj1.show_value("obj1");
    obj2.show_value("obj2"); 

    //����ex_class��ָ�����
    ex_class *p;

    //pָ��obj1����ʾ
    p=&obj1;
    p->show_value("p->obj1");

    //pָ��obj2����ʾ
    p=&obj2;
    (*p).show_value("(*p)obj2");

    //pָ��̬�����Ķ�����ʾ
    p=new ex_class;
    p->show_value("p->new");

    delete p;   //ɾ������

}
