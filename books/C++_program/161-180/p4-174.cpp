#include<iostream.h>

//�������뺯��ģ��
template <class T> void input(char *str,T &x) {
    cout<<str<<"=";
    cin>>x;
}

//�����������ģ��
template <class T> void output(char *str,T x) {
    cout<<str<<"="<<x<<endl;
}

//��main()�����в��������������ģ��
void main(void)
{
    //�������int������
    int a,b;
    input("a",a);
    output("a",a);
    b=3*a;
    output("3*a",b);
    output("a+b",a+b);
    cout<<"-------------------"<<endl;

    //�������double������
    double x,y;
    input("x",x);
    output("x",x);
    y=2*x;
    output("y",y);
    cout<<"-------------------"<<endl;

    //�������char������
    char c1;
    input("c1",c1);
    output("c1+2",char(c1+2));
    cout<<"-------------------"<<endl;

    //��������ַ�������
    char string[80];
    input("string",string);
    output("string",string);
}
