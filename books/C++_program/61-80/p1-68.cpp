#include<iostream.h>
//����f()����
f(int x,int y)     //f()�Ĳ�����ֵ��ʽ����
{
    ++x;
    --y;
    cout<<"x="<<x<<",y="<<y<<endl;
}
main()  {
    int a,b;

    //����ʵ�ʲ�����ֵ
    a=b=10;
    //�Ա���Ϊ��������f()����
    f(a,b);

    //��֤ʵ�ʲ�����ֵ
    cout<<"a="<<a<<",b="<<b<<endl;

    //�Ա���ʽ������ʽ����f()����
    f(2*a,a+b);
}