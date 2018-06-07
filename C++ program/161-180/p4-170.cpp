#include<iostream.h>

//������Ϊmax_value�ĺ���ģ��
template <class T> T max_value (T a,T b) 
{
    return ((a> b)? a: b);
}

//��main()�����в���max_value����ģ��
void main(void)
{
    //double��������ʹ��max_valueģ�庯��
    double x = 1.2, y = 2.1;
    cout<<"x="<<x<<"\t";
    cout<<"y="<<y<<endl;
    double result=max_value(x,y);
    cout<<"max_value(x,y)="<<result<<endl;
    cout<<"max_value(2*3.0,2+3.0)="<<max_value(2*3.0,2+3.0)<<endl;
    cout<<"------------------"<<endl;

    //int��������ʹ��max_valueģ�庯��
    int n= 1, m= 6;
    cout<<"n="<<n<<"\t";
    cout<<"m="<<m<<endl;
    cout<<"max_value(n,m)="<<max_value(n,m)<<endl;
    cout<<"------------------"<<endl;

    //char��������ʹ��max_valueģ�庯��
    char ch1='A',ch2='a';
    cout<<"ch1="<<ch1<<"\t";
    cout<<"ch2="<<ch2<<endl;
    cout<<"max_value(ch1,ch2)="<<max_value(ch1,ch2)<<endl;
    cout<<"------------------"<<endl;

    //�ַ�������ʹ��max_valueģ�庯��
    char str1[]="abc",str2[]="ABC",*p;
    p=max_value(str1,str2);
    cout<<"max_value("<<str1<<","<<str2<<")="<<p<<endl;
}
