#include <iostream.h>
// ex_class��ӿڶ���
class ex_class
{
private:
    int iv;
    double dv;
public:
    ex_class(void);
    ex_class(int n,double x);
    void set_ex_class(int n,double x);
    void show_ex_class(char*);
};

//����ex_class��Ĺ��캯��
ex_class::ex_class(void):iv(1), dv(1.0) { }
ex_class::ex_class(int n,double x):iv(n), dv(x) { }

//����ex_class��ĳ�Ա����
void ex_class::set_ex_class(int n,double x)
{
    iv=n;
    dv=x;
}
void ex_class::show_ex_class(char *name)
{
    cout<<name<<": "<<endl;
    cout <<"iv=" <<iv<< endl;
    cout <<"dv=" <<dv<< endl;
}
//ʹ��ex_class��
void main(void)
{
    ex_class obj1;
    obj1.show_ex_class("obj1");
    obj1.set_ex_class(5,5.5);
    obj1.show_ex_class("obj1");

    ex_class obj2(100,3.14);
    obj2.show_ex_class("obj2");
    obj2.set_ex_class(2000,1.732);
    obj2.show_ex_class("obj2");
}
