#include<iostream.h>

//����ģ���ԭ��
template <class T1, class T2> void display(T1 x, T2 y);

//��main()�����в���display����ģ��
void main(void)
{
    //��������
    char c='A';
    char str[]="This is a test";
    int n=10;
    float x=1.5;
    double z=3.1415926;

    //��������������ͬ
    display(c, char(c+2));
    display(str, str);
    display(n, 2*n);
    display(x,2*x);
    display(z, 2*z);
    cout<<"------------------"<<endl;

    //�����������Ͳ�ͬ
    display(c, str);
    display(str, c);
    display(n, str);
    display(str,2*x);
    display(z, n);
}

//������Ϊdisplay�ĺ���ģ��
template <class T1, class T2> void display(T1 x, T2 y)
{
    cout << x << " " << y << endl;
}
