#include<iostream.h>

//������Ϊex_class����ģ��
template <class T>  class ex_class
{
    T value;
public:
    ex_class(T v) { value=v; }
    void set_value(T v) { value=v; }
    T get_value(void) {return value;}
};

//main()�����в���ex_class��ģ��
void main(void)
{
    //����int��������
    ex_class <int> a(5),b(10);
    cout<<"a.value:"<<a.get_value()<<endl;
    cout<<"b.value:"<<b.get_value()<<endl;

    //����char��������
    ex_class <char> ch('A');
    cout<<"ch.value:"<<ch.get_value()<<endl;
    ch.set_value('a');
    cout<<"ch.value:"<<ch.get_value()<<endl;

    //����double��������
    ex_class <double> x(5.5);
    cout<<"x.value:"<<x.get_value()<<endl;
    x.set_value(7.5);
    cout<<"x.value:"<<x.get_value()<<endl;
}
